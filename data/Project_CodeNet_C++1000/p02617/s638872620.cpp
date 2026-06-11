#include <bits/stdc++.h>
using namespace std;
#define Dracarys ios_base::sync_with_stdio(false);cin.tie(NULL);
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()

inline void fileIO(bool &ptime){ 
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);ptime=true;
    #endif
}

clock_t start_time;
inline double getTime(){ return ((double)(clock()-start_time)/CLOCKS_PER_SEC); }


const int mxn = 2*1e5+5;
ll n;
inline void solve(ll tt){
    cin>>n;
    vector<array<ll,2>> edg;
    for (ll u,v,i=0;i<n-1;i++){
        cin>>u>>v;
        edg.pb({min(u,v),max(u,v)});
    }
    ll cnt=0;
    for (ll i=1;i<=n;i++){
        cnt+=(i*(i+1))/2;
    }
    for (auto &ed:edg){
        cnt-=((ed[0])*(n-ed[1]+1));
    }
    cout<<cnt<<"\n";
}

int main(){
        
    srand((unsigned)time(0));

    bool ptime=false;
    fileIO(ptime);
    start_time=clock();

    Dracarys

    ll tt=0,t=1;
    //cin>>t;

    while(t--){solve(++tt);}

    if (ptime)
    cerr<<getTime()<<endl;

    return 0;
}