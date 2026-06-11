#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    vector<ll> x(n-1), y(n-1);
    deque<ll> neg, pos;
    rep(i, n) {
        if (a[i] < 0) neg.push_back(a[i]);
        else pos.push_back(a[i]);
    }

    int cnt = 0;
    if (pos.size() == 0) {
        x[0] = neg[n-1]; neg.pop_back();
        y[0] = neg[n-2]; neg.pop_back();
        pos.push_back(x[0] - y[0]);
        cnt++;
    } else if (neg.size() == 0) {
        x[0] = pos[0]; pos.pop_front();
        y[0] = pos[1]; pos.pop_front();
        neg.push_back(x[0] - y[0]);
        cnt++;
    }

    while (neg.size() > 1) {
        x[cnt] = pos[0]; pos.pop_front();
        y[cnt] = neg[0]; neg.pop_front();
        pos.push_back(x[cnt] - y[cnt]);
        cnt++;
    }
    while (pos.size() > 1) {
        x[cnt] = neg[0]; neg.pop_front();
        y[cnt] = pos[0]; pos.pop_front();
        neg.push_back(x[cnt] - y[cnt]);
        cnt++;
    }
    ll ans = pos[0] - neg[0];
    x[n-2] = pos[0];
    y[n-2] = neg[0];
    cout << ans << endl;
    rep(i, n-1) {
        cout << x[i] << " " << y[i] << endl;
    }
}

