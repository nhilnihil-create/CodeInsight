#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> sum(n+1, 0);
    rep(i,n){
        cin >> sum[i+1];
        (sum[i+1] += sum[i]) %= k;
    }
    for(int i = 1; i <= n; ++i){
        sum[i] = (sum[i] + k - i % k) % k;
    }
    map<ll, ll> cnt;
    ll ans = 0;
    rep(i,n+1){
        if(i >= k) cnt[sum[i-k]]--;
        ans += cnt[sum[i]]++;
    }
    cout << ans << endl;
    return 0;
}
