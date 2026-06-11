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
   int x,n,index[303]={0};
   cin>>x>>n;
   int arr[n+3];
   for(int i=1;i<=n;i++) { cin>>arr[i]; index[arr[i]]=1; }
   int A=x;
   int B=x;
   int ans1,ans2;
   for(int i=1;i<=150;i++)
   {
      if(index[A]==0) { ans1=A; break; }
      A++;
   }
   for(int i=1;i<=150;i++)
   {
      B--;
      if(B>=0)
      {
         if(index[B]==0) { ans2=B; break; }
      }
   }
   int AA=abs(x-A);
   int BB=abs(x-B);
   if(AA>=BB) cout<<B<<endl;
   else cout<<A<<endl;

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
    //int t; scanf("%d",&t); while(t--) solve();
    solve();
}
