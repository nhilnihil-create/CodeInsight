#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    string s;
    cin >> s;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < (n-1)/2; i++) {
        if (s[i] != s[(n-1)/2-i-1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = (n+3)/2; i < n; i++) {
        if (s[i] != s[n-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0; 
}

