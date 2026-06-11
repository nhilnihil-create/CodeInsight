#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.length(); i++) {
        if(s[i] == s[i+1]) {
            s.erase(i,1);
            i--;
        }
    }

    cout << s.length() << endl;
}