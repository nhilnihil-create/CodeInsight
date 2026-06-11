#include<bits/stdc++.h>



#define ll long long
#define pb push_back
#define endl "\n"

using namespace std;
const ll maxn=1e3+100;
vector<ll> adj[29];


ll ans[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//   freopen("test.txt","r",stdin);
    //  freopen("PAINT.INP", "r", stdin);
    //  freopen("PAINT.OUT", "w", stdout);
    //  cout <<asdadasdasdadaasdad;
     ll n, m, a ,b ;
     cin>>n>>m>>a>>b;
     swap(a,b);
      for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
      {
        if (j<=b) ans[i][j]=1;
        else ans[i][j]=0;
      }
      for (int i=1;i<=a;i++)
      {
          for (int j=1;j<=m;j++)
          ans[i][j]=!ans[i][j];
      }
      for (int i=1;i<=n;i++)
      {
          for (int j=1;j<=m;j++)
          {
              cout <<ans[i][j];
          }
          cout <<endl;
      }



}
