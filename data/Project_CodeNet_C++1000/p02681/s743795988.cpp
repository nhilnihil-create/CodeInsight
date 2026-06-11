#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main (void){  
    string s, t;
    int cnt = 0;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[i]) {
            cnt++;
        }
    }

    if (s.length() == cnt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}