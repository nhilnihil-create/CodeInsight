#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[200010];
map<ll, int> mp;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    rep(i, n) cin >> a[i+1];

    rep(i, n) {
        a[i+1]--;
    }
    rep(i, n) {
        a[i+1] += a[i];
        a[i+1] %= k;
    }

    rep(i, min(ll(n+1),k)) mp[a[i]]++;

    ll cnt = 0;

    rep(i, n+1){
        // for(auto v : mp) cout << v.first << " " << v.second << endl;
        cnt += mp[a[i]] - 1;
        mp[a[i]]--;
        if (i+k < n+1) mp[a[i+k]]++;
    }

    cout << cnt << endl;

    return 0;
}