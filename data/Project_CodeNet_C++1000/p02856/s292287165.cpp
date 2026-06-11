#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll M;
    cin >> M;
    vector<ll> d(M), c(M);
    rep(i,M) cin >> d[i] >> c[i];
    ll all_sum = 0;
    rep(i,M) all_sum += (d[i] * c[i]);
    ll ans = 0;
    rep(i,M) ans += c[i];
    ll min_ll = 0;
    ans += max(min_ll, (all_sum + 8) / 9 - 1);
    cout << ans - 1 << endl;
}