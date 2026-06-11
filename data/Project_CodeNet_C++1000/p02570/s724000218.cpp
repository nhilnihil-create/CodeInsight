#include <iostream>
using namespace std;
 
int main() {
 
    int d, t, s;
    cin >> d >> t >> s;
 
    //Calculate the duration of Takahashi's journey
    double time = (double)d / s;
 
    //Output depending on the inequality between T and time
    if (t >= time) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}