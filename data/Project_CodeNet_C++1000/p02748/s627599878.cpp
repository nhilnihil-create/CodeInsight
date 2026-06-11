#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

signed main(){
    int A,B,M,amin,bmin;
    cin>>A>>B>>M;
    int a[A],b[B];
    int ans=0;
    amin=bmin=100000;
    REP(i,A){
        cin>>a[i];
        amin=min(amin,a[i]);   
    }
    ans+=amin;
    REP(i,B){
        cin>>b[i];
        bmin=min(bmin,b[i]);   
    }
    ans+=bmin;
    REP(i,M){
        int x,y,c;
        cin>>x>>y>>c;
        ans=min(ans,a[x-1]+b[y-1]-c);
    }
    cout<<ans<<endl;
}