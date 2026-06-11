#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);
    vector<ll> S(N+1);
    S.at(0)=0;
    rep(i,N){
        S.at(i+1)=S.at(i)+A.at(i);
        S.at(i+1)%=K;
    }
    vector<pair<ll,ll>> x(N+1);
    rep(i,N+1){
        x.at(i).first=((S.at(i)-i)%K+K)%K;
        x.at(i).second=i;
    }
    sort(x.begin(),x.end());
    queue<ll> change;
    rep(i,N){
        if(x.at(i).first!=x.at(i+1).first){
//cout<<i+1<<endl;
            change.push(i+1);
        }
    }
    change.push(N+1);
    ll cha=change.front();change.pop();
    ll ans=0;
    rep(i,N+1){
        if(i==cha){
            cha=change.front();change.pop();
        }
        pair<ll,ll> Q=x.at(i);
        Q.second+=K;
    //cout<<"("<<Q.second<<endl;
        ll plu=lower_bound(x.begin(),x.end(),Q)-x.begin();//ギリアウト
//cout<<plu<<endl;
        if(plu>cha){plu=cha;}
        plu-=i+1;
        if(plu>0){ans+=plu;}
    }
    cout<<ans<<endl;
}