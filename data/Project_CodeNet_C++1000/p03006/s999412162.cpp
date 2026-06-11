#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,ll>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<LP> ball(N);
    rep(i,N){
        cin>>ball.at(i).first>>ball.at(i).second;
    }
    set<LP> B;
    rep(i,N){
        B.insert(ball.at(i));
    }
    int ans=N;
    rep(i,50*50){
        int x,y;
        x=i/50;y=i%50;
        if(x==y)continue;
        if(x>=N || y>=N)continue;
        ll p=ball.at(x).first-ball.at(y).first,q=ball.at(x).second-ball.at(y).second;
        int now=0;
        rep(j,N){
            LP t=ball.at(j);
            t.first+=p;
            t.second+=q;
            if(!B.count(t))now++;
        }
        chmin(ans,now);
    }
    cout<<ans<<endl;
}