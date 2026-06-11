#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> x(n, 0);
    rep1(i, n) cin >> x[i];
    ll ans = INF;
    rep1(p, 100){
        ll sum = 0;
        rep1(i, n) sum += (x[i] - p) * (x[i] - p);
        ans = min(sum, ans);
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}