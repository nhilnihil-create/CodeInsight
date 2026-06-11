#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<pair<int64_t,int64_t>> P;
    rep(n,0,N){
        int64_t x,y; cin>>x>>y;
        P.emplace_back(x,y);
    }

    map<pair<int64_t,int64_t>,int> mp;
    rep(i,0,N)rep(j,0,N){
        if(i!=j) mp[make_pair(P.at(i).first-P.at(j).first,P.at(i).second-P.at(j).second)]++;
    }

    int ans=0;
    for(auto m:mp){
        //cout<<m.first.first<<" "<<m.first.second<<" "<<m.second<<endl;
        ans=max(ans,m.second);
    }

    ans=N-ans;
    cout<<ans<<endl;
}