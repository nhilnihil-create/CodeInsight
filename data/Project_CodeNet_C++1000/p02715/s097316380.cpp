#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;

ll mod_pow(ll x, ll n){ //べき乗
    ll ans=1;
    x%=MOD;
    while(n!=0){
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n=n>>1;
    }
    return ans%MOD;
}

int main(){
    int N,K; cin >> N >> K;
    ll ans=0;
    map<int,ll> ma;
    for(int i=K;i>=1;i--){
        int tmp=K/i;
        ll res=mod_pow(tmp,N);
        for(int j=2;j<=tmp;j++){
            ll k=i*j;
            res=(res-ma[k]+MOD)%MOD;
        }
        ma[i]=res;
        ans+=(res*i)%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
}