#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    vector<bool> prev(n, true);
    repl(i, k, n) {
        if(t[i - k] == t[i] && prev[i - k]) prev[i] = false;
    }
    int ans = 0;
    rep(i, n) {
        if(t[i] == 'r' && prev[i]) ans += p;
        if(t[i] == 's' && prev[i]) ans += r;
        if(t[i] == 'p' && prev[i]) ans += s;
    }
    cout << ans << endl;
    return 0;
}
