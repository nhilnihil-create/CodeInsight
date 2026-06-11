#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] = (a[i] - 1) % k;
    }
    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i, n) {
        sum[i+1] = (sum[i] + a[i]) % k;
    }
    ll ans = 0;
    map<int, int> mp;
    rep(i, n+1) {
        if (i<k) {
            ans += mp[sum[i]];
            mp[sum[i]]++;
        }
        else {
            mp[sum[i-k]]--;
            ans += mp[sum[i]];
            mp[sum[i]]++;
        }
    }
    
    
    cout << ans << endl;
    return 0;
}
