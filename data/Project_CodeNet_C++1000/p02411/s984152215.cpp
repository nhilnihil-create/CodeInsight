#include <iostream>
using namespace std;

int main() {
    int m,f,r;

    cin >> m >> f >> r;
    while(m!=-1 || f != -1 || r!= -1) {
        string grade;
        int score;

        score = m+f;
        if(m==-1 || f ==-1)
        {
            grade = "F";
        }
        else if(score >= 80)
        {
            grade = "A";
        }
        else if(score < 80 && score >= 65)
        {
            grade = "B";
        }
        else if(score < 65 && score >= 50)
        {
            grade = "C";
        }
        else if(score < 50 && score >= 30)
        {
            if(r>=50)
                grade = "C";
            else
                grade = "D";
        }
        else
            grade = "F";

        cout << grade << endl;

        cin >> m >> f >> r;
    }
}