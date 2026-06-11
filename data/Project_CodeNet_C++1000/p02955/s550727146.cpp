#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;



int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);
    ll sum=0;
    rep(i,N)sum+=A.at(i);
    vector<ll> kouho(0);
    for(int i=1;i*i<=sum;i++){
        if(sum%i==0){kouho.pb(i);}
    }
//rep(i,sz(kouho))cout<<kouho.at(i)<<" ";
//cout<<endl;
    int s=sz(kouho);
    rep(i,s){int j=sum/kouho.at(s-1-i);kouho.pb(j);}
//rep(i,sz(kouho))cout<<kouho.at(i)<<" ";
    ll ans=1;
    rep(i,sz(kouho)){
        ll d=kouho.at(i);
        vector<ll> amari(N),ruiplus(N+1),ruiminus(N+1);
        rep(j,N){amari.at(j)=A.at(j)%d;}
        sort(amari.begin(),amari.end());
        rep(j,N){
            ruiplus.at(j+1)=ruiplus.at(j)+amari.at(j);
            ruiminus.at(j+1)=ruiminus.at(j)+d-amari.at(N-j-1);
        }
/*cout<<"kouho="<<d<<endl;
rep(j,N+1)cout<<ruiplus.at(j)<<" ";
cout<<endl;
rep(j,N+1)cout<<ruiminus.at(j)<<" ";
cout<<endl;*/
        ll mn,mx;
        for(int j=0;j<=N;j++){
            mx=max(ruiplus.at(j),ruiminus.at(N-j));
            if(j==0){mn=mx;}
            chmin(mn,mx);
        }
//cout<<"mx="<<mx<<endl;
        if(mn<=K){ans=max(ans,d);}
    }
    cout<<ans<<endl;
}
