#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    int N,M,ans=0,k=0;cin>>N>>M;
    vector<pair<int,int>>vec(N);
    REP(i,N){
        int a,b;cin>>a>>b;
        vec[i]={a,b};
    }
    sort(vec.begin(),vec.end());
    priority_queue<int>q;
    REPS(i,M){
      	while(k<=N-1&&vec[k].first==i){
            q.push(vec[k].second);
            k++;
        }
        if(!q.empty()){
            ans+=q.top();q.pop();
        }
    }
    cout<<ans<<endl;
}