#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            1e18


void solve()
{
   long long a,b,c,d;
   cin>>a>>b>>c>>d;
   long long ans=0;
   if(d<=a) { ans+=d; d=0; }
   else { ans+=a; d-=a; }
   if(d==0) { cout<<ans<<endl; return; }
   if(d<=b) { d=0; }
   else { d-=b; }
   if(d==0) { cout<<ans<<endl; return; }
   if(d<=c) { ans-=d; d=0; }
   else { ans-=c; d-=a; }
   if(d==0) { cout<<ans<<endl; return; }
   cout<<ans<<endl;

}

int main()
{
    fast
    #ifndef ONLINE_JUDGE
    //Read;
    //Write;
    #endif
    //sieve();
    //int cnt=1;
    //int t; cin>>t; while(t--) solve();
    solve();
}
