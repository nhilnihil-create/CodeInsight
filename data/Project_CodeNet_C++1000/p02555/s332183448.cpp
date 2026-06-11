//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define inf 1000000000000000000
#define mem(name,val) memset(name,val,sizeof(name))
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif 
   int s;cin>>s;
   int dp[s+3];mem(dp,0);dp[0]=1;
   for(int i=1;i<=s;i++)
   {
    for(int j=3;j<=s;j++)
    {
      if(i>=j)
      {
      dp[i]+=dp[i-j];dp[i]%=mod;
      }
    }
   }
   cout<<dp[s]; 
}