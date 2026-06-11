#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<queue<ll>> q(n);
    rep(i, n) {
        rep(j, n - 1) {
            ll a;
            cin >> a;
            a--;
            q[i].push(a);
        }
    }
    set<ll> s;
    queue<pair<ll, ll>> kh;
    rep(i, n) {
        if (s.count(i) > 0) continue;
        ll next = q[i].front();
        if (q[next].front() == i) {
            kh.push(make_pair(i, next));
            s.insert(i);
            s.insert(next);
        }
    }
    ll days = 0;
    while(!kh.empty()) {
        s.clear();
        queue<pair<ll, ll>> next;
        while(!kh.empty()) {
            pair<ll, ll> p = kh.front();
            kh.pop();
            if (sz(q[p.first]) > 0) {
                ll pfn = q[p.first].front();
                if ((q[pfn].front() == p.first) && (s.count(p.first) == 0) && (s.count(pfn) == 0)) {
                    q[p.first].pop();
                    q[pfn].pop();
                    next.push(make_pair(p.first, pfn));
                    s.insert(p.first);
                    s.insert(pfn);
                }
            }
            if (sz(q[p.second]) > 0) {
                ll psn = q[p.second].front();
                if ((q[psn].front() == p.second) && (s.count(p.second) == 0) && (s.count(psn) == 0)) {
                    q[p.second].pop();
                    q[psn].pop();
                    next.push(make_pair(p.second, psn));
                    s.insert(p.second);
                    s.insert(psn);
                }
            }
        }
        while(!next.empty()) {
            kh.push(next.front());
            next.pop();
        }
        days++;
    }
    ll remain = 0;
    rep(i, n) remain += sz(q[i]);
    if (remain > 0) {
        cout << -1 << endl;
    }
    else {
        cout << (days - 1) << endl;
    }
    return 0;
}
