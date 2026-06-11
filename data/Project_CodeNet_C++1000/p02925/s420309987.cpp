#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<queue<ll>> a(n);
    rep(i, n) {
        rep(j, n - 1) {
            ll tmp;
            cin >> tmp;
            a[i].push(tmp - 1);
        }
    }
    set<ll> check;
    rep(i, n) check.insert(i);
    bool upd = true;
    ll ans = 0;
    set<ll> emp;
    while(upd) {
        upd = false;
        set<ll> next;
        for(auto &x : check) {
            if (a[x].empty()) continue;
            ll u = a[x].front();
            if (a[u].empty()) continue;
            ll v = a[u].front();
            if ((v == x) && (next.count(x) == 0) && (next.count(u) == 0)) {
                next.insert(x);
                next.insert(u);
                a[x].pop();
                if (a[x].empty()) emp.insert(x);
                a[u].pop();
                if (a[u].empty()) emp.insert(u);
                upd = true;
            }
        }
        if ((!upd) && (sz(emp) != n)) {
            cout << -1 << endl;
            return 0;
        }
        check = next;
        ans++;
        if (sz(emp) == n) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
