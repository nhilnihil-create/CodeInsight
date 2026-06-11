#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N,M,ans=0,k=0;cin>>N>>M;
    vector<pair<int,int>>vec(N);
    REP(i,N){
        int a,b;cin>>a>>b;
        vec[i]=mp(a,b);
    }
    sort(vec.begin(),vec.end());
    priority_queue<int> que;
    for(int i=M-1;i>=0;i--){
        while(k<=N&&vec[k].first==M-i){
            que.push(vec[k].second);
            k++;
        }
        if(!que.empty()){
			ans+=que.top();
        	que.pop();
        }
    }
    cout<<ans<<endl;
}
