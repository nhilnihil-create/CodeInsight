#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    string res = "Yes";
    rep (i, s.size()) {
        if (i % 2 == 0 && s[i] == 'L') res = "No";
        else if (i % 2 == 1 && s[i] == 'R') res = "No";
    }
    cout << res << endl;
}