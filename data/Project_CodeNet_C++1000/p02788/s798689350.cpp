#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pii> mon(n);
    int x, h;
    for (int i = 0; i < n; ++i) {
        cin >> x >> h;
        mon[i] = pii(x, (h + a-1) / a);
    }
    sort(all(mon));

    ll res = 0;
    ll now = 0;
    int j = 0;
    vector<ll> v(n, 0);
    for (int i = 0; i < n; ++i) {
        now += v[i];
        if (now >= mon[i].second) continue;
        for (;j < n; ++j) {
            if (mon[j].first > mon[i].first + 2 * d){
                v[j] -= mon[i].second - now;
                break;
            }
        }
        res += mon[i].second - now;
        now = mon[i].second;
    }
    cout << res << endl;
}