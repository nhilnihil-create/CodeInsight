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
const ll MOD=1000000007,MOD2=998244353;



int main() {
    ll N,K;
    cin>>N>>K;
    vector<int> A(N);
    rep(i,N)cin>>A.at(i);
    ll ans=0;
    rep(i,N){
        ll bef=0,aft=0;
        rep(j,N){
            if(A.at(j)<A.at(i)){
                if(j<i){
                    bef++;
                }
                else{aft++;}
            }
        }
        ll plu=(K+1)*K/2;
        plu%=MOD;
        plu*=(bef+aft);
        plu-=K*bef;
        plu%=MOD;
        ans+=plu;
        ans%=MOD;
    }
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<endl;
}