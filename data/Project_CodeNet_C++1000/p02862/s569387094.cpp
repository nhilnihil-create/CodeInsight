#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

vll prime_factrize(ll n){
    vll prime_factrize_ret;
    ll temp=n;
    for(ll i=2;i*i<=n;i++){
        while(temp%i==0){
            prime_factrize_ret.push_back(i);
            temp/=i;
        }
    }
    if(temp!=1) prime_factrize_ret.push_back(temp);
    return prime_factrize_ret;
}

ll fast_pow(ll n,ll a,ll mod){
    ll res=1;
    while(a>0){
        if(a&1) res=res*n%mod;
        n=n*n%mod;
        a>>=1;
    }
    return res;
}

ll mod_inv(ll n, ll mod){
    return fast_pow(n,mod-2,mod);
}

ll comb(ll n, ll r, ll mod){
    ll temp=1;
    for(int i=r+1;i<=n;i++){
        temp=(temp*i)%mod;
    }
    ll temp2=1;
    for(int i=2;i<=n-r;i++){
        temp2=(temp2*i)%mod;
    }
    return temp*mod_inv(temp2,mod)%mod;
}

int main(){
    int x,y;
    cin >> x >> y;
    int n,m;
    n=(2*x-y)/3;
    m=(2*y-x)/3;
    if(n<0||m<0||(x+y)%3!=0){
        cout << "0" << endl;
        return 0;
    }    
    cout << comb(n+m,n,MOD) << endl;    
}