#include <iostream>
using namespace std;

// Base Class: Student
class Student {

protected:
    string name;
    int rollNo;

public:
    
// Constructor overloading
    Student() {
        name = "Unknown";
        rollNo = 0;
    }

    Student(string n, int r) {
        name = n;
        rollNo = r;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }

    string getName() {
      
  return name;
    }

    int getRoll() {
        return rollNo;
    }
};


// Derived Class: Marks
class Marks : public Student {
protected:
    int m1, m2, m3;

public:
    Marks() : Student() {
       
 m1 = m2 = m3 = 0;
    }

    Marks(string n, int r, int a, int b, int c) : Student(n, r) {
        m1 = a;
        m2 = b;
        m3 = c;
    }

    int totalMarks() {
        return m1 + m2 + m3;
    }

    float average() {
        
return totalMarks() / 3.0;
    }

    void display() override {
        cout << "\n--- Student Report ---" << endl;
        Student::display();
        cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
        cout << "Total: " << totalMarks() << endl;
        cout << "Average: " << average() << endl;
   
 }
};

// Derived Class: Grade
class Grade : public Marks {
    char grade;

public:
    Grade() : Marks() {
        
grade = 'F';
    }

    Grade(string n, int r, int a, int b, int c) : Marks(n, r, a, b, c) {
        float avg = average();
        if (avg >= 90)
            grade = 'A';
        else if (avg >= 75)
            grade = 'B';
        else if (avg >= 50)
            grade = 'C';
        
else
            grade = 'F';
    }

    char getGrade() {
        return grade;
    }

    void display() override {
        Marks::display();
        
cout << "Grade: " << grade << endl;
    }
};

// Function to find the topper
void findTopper(Grade *students[], int n) {
    int maxMarks = -1, index = -1;
    for (int i = 0; i < n; i++) {
        int total = students[i]->totalMarks();
        if (total > maxMarks) {
            maxMarks = total;
           
 index = i;
        }
    }

    if (index != -1) {
        cout << "\n Topper of the Class " << endl;
        students[index]->display();
    }

}

// Function to search student by roll number
void searchStudent(Grade *students[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (students[i]->getRoll() == roll) {
            cout << "\nStudent Found!" << endl;
            students[i]->display();
            return;
        }
    }
    
cout << "No student found with Roll No: " << roll << endl;
}

// Main function
int main() {
    int n, choice;
    cout << "Enter number of students: ";
    cin >> n;

    Grade *students[n];

    for (int i = 0; i < n; i++) {
        
string name;
       
int roll, m1, m2, m3;
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        
cout << "Roll No: ";
        cin >> roll;
        cout << "Enter marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        students[i] = new Grade(name, roll, m1, m2, m3);
    }

    do {
        cout << "\n===== STUDENT REPORT CARD SYSTEM =====" << endl;
        cout << "1. Display All Reports" << endl;
        cout << "2. Search Student by Roll No" << endl;
        
cout << "3. Show Class Topper" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n===== ALL STUDENT REPORTS =====" << endl;
            for (int i = 0; i < n; i++) {
                students[i]->display();
            }
            break;

        case 2: {
           
 int roll;
           
cout << "Enter Roll No to search: ";
            
cin >> roll;
            searchStudent(students, n, roll);
            break;
        }

        case 3:
            findTopper(students, n);
            break;

        case 4:
            cout << "Exiting Program. Thank you!" << endl;
            break;

        
default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}








