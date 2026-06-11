#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mex=5001;
#define ll long long 
#define test int t;cin>>t;while(t--)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,n) for(int i=a;i<n;i++)
#define rfo(i,a,b) for(int i=a;i>=b;i--)
#define bg begin()
#define en end()
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define veci vector<int>
#define veclli vector<long long int> 
#define all(x) x.begin(),x.end()
#define sci(x) scanf("%d",&x);
#define scc(x) scanf("%c",&x);
#define scs(x) scanf("%s",x);
#define debug(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);
#define sz(x) x.size()
#define loop(x) for(auto it=x.begin();it!= x.end();it++) 
 
 ll int dp[5001][5001]={0};
int main()
{
  int n,k;
  cin>>n>>k;
  fo(i,0,n+1)
  dp[i][0]=1;
  fo(j,1,k+1)
  fo(i,1,n+1)
  dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;

  fo(i,1,k+1)
  {
    ll int an=(dp[k-1][i-1]*dp[n-k+1][i])%mod;
    cout<<an<<" ";
  }


 // cout<<cnt<<endl;
}