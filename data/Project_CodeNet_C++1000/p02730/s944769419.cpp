#include <bits/stdc++.h>
using namespace std;

bool isparindrome(const string &s) {
    int n = s.size();
    for (int i=0; i<n/2; i++) {
        if (s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}
bool solve(const string &s) {
    int n = s.size();
    return isparindrome(s) && isparindrome(s.substr(0,n/2)) && isparindrome(s.substr((n+1)/2,n/2));
}

int main() {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
}
