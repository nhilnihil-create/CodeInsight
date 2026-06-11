#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]++;
    int mx = 0;
    int s = 0;
    queue<int> q;
    rep(i, n) {
        s += p[i];
        q.push(p[i]);
        if(q.size() > k) {
            s -= q.front();
            q.pop();
        }
        if(q.size() == k) {
            mx = max(mx, s);
        }
    }
    double ans = mx;
    ans /= 2;
    cout << setprecision(10) << ans << endl;
    return 0;
}