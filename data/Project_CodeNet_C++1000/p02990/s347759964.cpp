#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

ll nck(ll n, ll k){
    
    ll p=1000000007;
    ll p2;
    p2=p-2;
    vector <int> r(35);
    vector <ll> r2(36);

    rep(j,35){
        r[j]=(p2>>j)&1;
    }

    ll ans;
    ans=1;

    if (k!=0){
    rep(i,k-1){   
        r2[0]=i+2;
        rep(j,35){
           
            r2[j+1]=(r2[j]*r2[j])%p;
            if(r[j]==1){
            ans*=r2[j];
            ans=ans%p;
            }
        }
    }
    rep(i,k){
        ans*=n-i;
        ans=ans%p;
    }
    }
    return ans;
}

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans;
    ans=0;

    rep(i,k){
        ans=nck(n-k+1,i+1)*nck(k-1,k-i-1);
        ans=ans%1000000007;
        cout << ans << endl;
    }

    
    

    return 0;
}