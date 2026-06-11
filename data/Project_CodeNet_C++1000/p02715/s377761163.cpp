#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const ll mod = 1e9 + 7;

ll powmod(ll a,ll b,ll p){
    // a^b mod p を返す
    if(b==0 || a == 1)return 1;
    ll ret = 1;
    while(b){
        if(b%2==0){
            a = (a*a)%mod;
            b/=2;
        }else {
            ret *= a;
            ret %= mod;
            b--;
        }
    }
    return ret%mod;
}

vector<int> div(int x){
    vector<int> ret;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(i*i==x)ret.push_back(i);
            else{
                ret.push_back(i);
                ret.push_back(x/i);
            }
        }
    }
    return ret;
}

ll d[100005];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(int i=k;i>0;i--){
        // gcd がiの倍数の数列の個数 cnt 
        ll cnt = (powmod(k/i,n,mod) - d[i] + mod)%mod;
        ans += (i * cnt) % mod;
        ans %= mod;
        auto v = div(i);
        for(auto x:v){
            d[x] += cnt;
            d[x] %= mod;
        }
    }
    cout << ans % mod << endl;
}