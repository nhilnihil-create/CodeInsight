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
    ll a,b,n;
    cin >> n >> a >> b;

    ll ans2,k2;
    vector <ll> si(35,0),amari(35,0);
    k2=2;

    rep(i,35){
        si[i]=((n>>i)&1);
        amari[i]=k2;
        k2=(k2*k2)%1000000007;
    }

    ans2=1;
    rep(i,35){
        if(si[i]==1){
        ans2*=si[i]*amari[i];
        ans2=ans2%(1000000007);
        }
    }

    ans2-=nck(n,a)+nck(n,b)+1;
    while(ans2<0){
        ans2+=1000000007;
    }


    if(n<=2){
        ans2=0;
    }
    cout << ans2 << endl;



    return 0;
}