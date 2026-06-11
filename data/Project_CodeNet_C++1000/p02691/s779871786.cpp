#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
 
signed main(){
    int N;cin>>N;
    map<int,int>Amemo;
    map<int,int>Bmemo;
    REP(i,N){
        int a;cin>>a;
        Amemo[a+i]++;
        Bmemo[a-i]++;
    }
    int ans=0;
    for(auto v:Amemo){
        int pls=Amemo[v.first]*Bmemo[-v.first];
        ans+=pls;
    }
    cout<<ans<<endl;
}
