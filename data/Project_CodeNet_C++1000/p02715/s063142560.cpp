#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, ans=0, tmp=0;
vector<ll> A;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
    cin >> N >> K;
    A.resize(K+1);
    for(int i=K;i>0;i--) {
        A[i] = modpow(K/i, N, MOD);
        for(int j=2*i;j<=K;j+=i) {
            A[i] -= A[j];
        }
        ans += i*A[i];
        ans %= MOD;
        if(ans<0) ans += MOD;
    }
    cout << ans << endl;
    return 0;
}