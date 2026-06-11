#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;


#define N_MAX 201010
ll f[N_MAX],rf[N_MAX];   
//f[n]  := n!
//rf[n] := (n!)^-1

ll modpow(ll a,ll b){    // aのb乗
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

void init(){
    f[0] = 1;
    for(ll i = 1; i < N_MAX; i++){
        f[i] = (i * f[i-1]) % mod;
    }
    for(ll i = 0; i < N_MAX; i++){
        rf[i] = modpow(f[i],mod-2);
    }
}

ll com(ll n, ll k){
    //init();
    ll a = f[n];
    ll b = rf[k];
    ll c = rf[n-k];

    ll bc = (b * c) % mod;

    return ((a * bc) % mod);
}


int main()
{
    ll s; cin >> s;
    ll ans = 0;
    ll num = 1;
    init();
    while(s / num >= 3){
        ll n = s - num*3;
        ans += com(n+num-1,num-1);
        ans %= mod;
        num++;
    }
    cout << ans << endl;
}