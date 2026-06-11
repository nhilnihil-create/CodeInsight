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
    vector<ll> a(n, 0), ans(n);
    ll sum = 0, res = 0;
    rep1(i, n){
        cin >> a[i];
        sum += a[i];
        if (i%2==1) res += a[i];
    }
    ans[0] = sum - 2*res;
    for (ll i=1; i<(n); i++){
        ans[i] = 2 * (a[i-1] - ans[i-1]/2);
    }
    rep1(i, n){ 
        if (i==n-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    //printf("%.12f", ans);
}