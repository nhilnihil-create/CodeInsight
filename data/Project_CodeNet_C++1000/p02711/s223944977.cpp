#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            99999999999999


void solve()
{
  int n;
  cin>>n;
  while(n>0)
  {
      if(n%10==7)
      {
          cout<<"Yes"<<endl;
          return;
      }
      n/=10;
  }
  cout<<"No"<<endl;


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
