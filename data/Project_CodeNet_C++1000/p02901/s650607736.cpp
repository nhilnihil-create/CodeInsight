#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define int long long
#define f(i,l,n) for(ll i=l;i<n;i++) 
#define E "\n"
#define bp __builtin_popcount

 ll n,m;
 const int M=1e3+5;
ll Ans=1e15;
vector<ll> a(M),b(M);
vector<ll> c[M];
int dp[M][5000];


int solve(int indx,int mask)
{
  //cout<<indx<<" "<<mask<<E;
    if(indx>=m) return (bp(mask)>=n)?0:1e15;
    if(bp(mask)==n) return 0;


    int &ans=dp[indx][mask];
    if(ans!=-1) return ans;

    ans=1e15;
    ans=solve(indx+1,mask);
    f(i,0,b[indx])  mask=mask|(1<<c[indx][i]-1);
    ans=min(ans,a[indx]+solve(indx+1,mask));
 //   cout<<indx<<" "<<mask<<" "<<ans<<E;

    return ans;


}


int32_t main()
{

   

    cin >> n >> m;

    f(i,0,m)
    {
      cin >> a[i] >> b[i];
      f(j,0,b[i])
      {
        ll x;
        cin >> x;
        c[i].push_back(x);
      }
    }

    

    

    f(i,0,m+1) f(j,0,5000) dp[i][j]=-1;

    Ans=solve(0,0);

    (Ans>=1e15)?cout<<"-1":cout<<Ans;


     return 0;
}