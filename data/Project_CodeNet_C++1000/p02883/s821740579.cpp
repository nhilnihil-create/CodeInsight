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

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    sort(all(a));
    sort(rall(f));
    ll l = -1;
    ll r = LINF;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll num = 0;
        for (int i = 0; i < n; ++i) {
            num += max(0LL, a[i] - m / f[i]);
        }
        if (num <= k) r = m;
        else l = m;
    }
    cout << r << endl;
}