#include "bits/stdc++.h"
#define rep(i,n) for (ll i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

//x^nをmodで計算する関数
ll sisu(ll x,ll n){
    ll mod=1e9+7;
    ll nv=n;
    vector <ll> bi(40,0);
    vector <ll> cal(40,0);
    ll k=0;
    ll ans=1;
    while(nv!=0){
        bi[k]=nv%2;
        nv/=2;
        ++k;
    }
    rep(i,40){
        if(i==0){
            cal[i]=x%mod;
        }
        else{
            cal[i]=(cal[i-1]*cal[i-1])%mod;
        }
        if(bi[i]==1){
            ans*=cal[i];
            ans=ans%mod;
        }
    }

    return ans;
}

int main(){
    ll n,k;
    cin >> n >> k;
    vector <ll> in(k+1,0);
    ll nn;

    vector <vector <ll>> y(k+1);

    rep(i,k){
        in[i+1]=k/(i+1);
        nn=2;
        while(nn*(i+1)<=k){
            y[nn*(i+1)].push_back(i+1);
            ++nn;
        }
    }

    

    vector <ll> mi(k+1,0);
    ll l;
    ll ans=0;
    ll mod=1e9+7;

    //cout << sisu(in[8],n) << endl;
    //cout << sisu(7,8) << endl;
    //cout << sisu(2,5) << endl;


    ll ko,mi2;

    rep(i,k){
        nn=k-i;
        //cout << nn << endl;
        
        l=y[nn].size();
        ko=sisu(in[nn],n);
        mi2=mi[nn];
        rep(j,l){
            mi[y[nn][j]]+=(ko-mi2);
        }
        //cout << in[nn] << " " << n << endl;
       
        //cout << sisu(1,3) << endl;
        ans+=(ko-mi2)*nn;
        //cout << 777 << endl;
        ans=ans%mod;
    }
    while(ans<0){
        ans+=mod;
    }

    cout << ans << endl;
    

    return 0;
}