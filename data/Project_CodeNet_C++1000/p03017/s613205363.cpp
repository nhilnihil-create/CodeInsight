#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int n, a, b, c, d;
    string s;
    cin >>  n >> a >> b >> c >> d >> s;
    //a--; b--; c--; d--;
    int i = a;
    s = '#' + s + '#';
    if(c < d) {
        for(int i = a; i <= d; i++) {
            if(s[i] == s[i-1] && s[i] == '#') {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else {
        for(int i = a; i <= c; i++) {
            if(s[i] == s[i-1] && s[i] == '#') {
                cout << "No" << endl;
                return 0;  
            }
        }
        int flag = 0;
        for(int i = b; i <= d; i++) {
            if(s[i] == '.' && s[i-1] == '.' && s[i+1] == '.') {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;

}