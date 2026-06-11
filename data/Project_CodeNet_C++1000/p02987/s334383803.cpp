#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << (s[0] == s[1] && s[2] == s[3] && s[1] != s[2] ? "Yes\n" : "No\n");
    return 0;
}
