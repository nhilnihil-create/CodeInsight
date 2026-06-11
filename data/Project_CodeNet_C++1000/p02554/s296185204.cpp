#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

ll modpow(ll a,ll b){    // aのb乗
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main()
{
    ll n; cin >> n;
    if(n == 1) cout << 0 << endl;
    else{
        ll ans = modpow(10,n);
        ll sub = 2 * modpow(9,n) - modpow(8,n);
        sub %= mod;
        ans -= sub;
        ans = (ans%mod+mod) % mod;
        cout << ans << endl;
    }
}