#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s[n -1] == 's') {
        s.push_back('e');
    }
    s.push_back('s');
    cout << s;
}