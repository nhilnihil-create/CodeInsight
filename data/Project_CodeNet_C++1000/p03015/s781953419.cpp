#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string l;
    cin>>l;
    int S=sz(l);
    vector<int> L(S);
    rep(i,S){
        L.at(i)=l.at(i)-'0';
    }
    vector<vector<ll>> dp(2,vector<ll>(S+1));//0はa+b=L?,1はa+b<L
    dp.at(0).at(0)=2;
    dp.at(1).at(0)=1;
    for(int i=1;i<S;i++){
        if(L.at(i)){
            dp.at(0).at(i)+=dp.at(0).at(i-1)*2;
            dp.at(0).at(i)%=MOD;
            dp.at(1).at(i)+=dp.at(0).at(i-1);
            dp.at(1).at(i)%=MOD;
            dp.at(1).at(i)+=dp.at(1).at(i-1)*3;
            dp.at(1).at(i)%=MOD;
        }
        else{
            dp.at(0).at(i)+=dp.at(0).at(i-1);
            dp.at(0).at(i)%=MOD;
            dp.at(1).at(i)+=dp.at(1).at(i-1)*3;
            dp.at(1).at(i)%=MOD;
        }
    }
    ll ans=dp.at(0).at(S-1);
    ans+=dp.at(1).at(S-1);
    ans%=MOD;
    cout<<ans<<endl;
}