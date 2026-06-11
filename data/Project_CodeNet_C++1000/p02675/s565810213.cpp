#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main (void){  
    string n;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n.length(); i++) {
        cnt++;
    }

    if (cnt == 1) {
        if (n[0] == '3') {
            cout << "bon" << endl;
        } else if (n[0] == '0' || n[0] == '1' || n[0] == '6'|| n[0] == '8') {
            cout << "pon" << endl;
        } else {
            cout << "hon" << endl;
        }
    } else if (cnt == 2) {
        if (n[1] == '3') {
            cout << "bon" << endl;
        } else if (n[1] == '0' || n[1] == '1' || n[1] == '6'|| n[1] == '8') {
            cout << "pon" << endl;
        } else {
            cout << "hon" << endl;
        }
    } else {
        if (n[2] == '3') {
            cout << "bon" << endl;
        } else if (n[2] == '0' || n[2] == '1' || n[2] == '6'|| n[2] == '8') {
            cout << "pon" << endl;
        } else {
            cout << "hon" << endl;
        }
    }
    return 0;
}