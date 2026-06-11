#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2]) cout << "Yes";
  	else cout << "No";
}
