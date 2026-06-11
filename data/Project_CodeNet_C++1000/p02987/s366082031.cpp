#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    string s;
    cin >> s;
    bool ok = true;
    sort(s.begin(), s.end());
    if (s[0] != s[1]) ok = false;
    if (s[1] == s[2]) ok = false;
    if (s[2] != s[3]) ok = false;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}