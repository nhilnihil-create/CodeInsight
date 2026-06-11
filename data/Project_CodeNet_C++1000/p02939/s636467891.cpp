#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string t, p = "";
    int ans = 0;
    rep(i, s.size()) {
        t += s[i];
        if(t == p) continue;
        p = t;
        t = "";
        ans++;
    }
    cout << ans << endl;
    return 0;
}
