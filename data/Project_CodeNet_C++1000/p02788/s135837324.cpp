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
    ll N,D,A;
    cin>>N>>D>>A;
    vector<pair<ll,ll>> M(N);
    rep(i,N){
        cin>>M.at(i).first>>M.at(i).second;
        M.at(i).second=(M.at(i).second-1)/A+1;
    }
    sort(M.begin(),M.end());
    ll bomb=0,ans=0;
    queue<P> range;
    rep(i,N){
        while(!range.empty() && range.front().first<M.at(i).first){
            P f=range.front();range.pop();
            bomb-=f.second;
        //cout<<bomb<<endl;
        }
        if(M.at(i).second-bomb>0){
            ans+=M.at(i).second-bomb;
            range.push({M.at(i).first+2*D,M.at(i).second-bomb});
            bomb+=M.at(i).second-bomb;
        }
        //cout<<bomb<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}