#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

#define N_MAX 201010
ll f[N_MAX],rf[N_MAX];

ll pow(ll x,ll n){  // xのn乗 (mod m)
    ll res = 1;
    if(n > 0){
        res = pow(x,n / 2);
        if(n % 2 == 0){
            res = (res * res) % mod;
        }else{
            res = (((res * res) % mod) * x) % mod;
        }
    }
    return res;
}

void init(){
    f[0] = 1;
    for(int i = 1; i < N_MAX; i++){
        f[i] = (i * f[i-1]) % mod;
    }
    for(int i = 0; i < N_MAX; i++){
        rf[i] = pow(f[i],mod-2);
    }
}

ll com(ll n, ll k){
    ll a = f[n];
    ll b = rf[k];
    ll c = rf[n-k];

    ll bc = (b * c) % mod;

    return (a * bc) % mod;
}

int main()
{
    ll n,k; cin >> n >> k;
    init();
    for(int i = 1; i <= k; i++){
        ll ans;
        if(n-k+1 >= i){
            ans = com(n-k+1,i) * com(k-1,i-1);
        }else{
            ans = 0;
        }
        ans %= mod;
        cout << ans << endl;
    }
}