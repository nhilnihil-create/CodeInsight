#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define mod 998244353
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int solve(int N, vector<int> v)
{
    int dp[N+1];
    dp[1] = 1; 
    for(int i = 2; i <= N; i++)
    {
        dp[i] = 0; 
        for(int j = 0; j < v.size(); j++)
            if(v[j] < i)
                dp[i] = (dp[i]%mod + dp[i-v[j]]%mod)%mod;
    }
    return dp[N];
}

int main()
{
   flash;
   //sieve();
   ll T=1,t,n,m,q,k,i,j;
   // cin>>T;
   while(T--)
   {
      string sr;
      cin>>sr;
      cout<<sr;
      if(sr[sr.length()-1]=='s')
         cout<<'e';
      cout<<'s';
      // cin>>n>>k;
      // vector<int> vec;
      // FOR(i,0,k)
      // {
      //    cin>>m>>t;
      //    FOR(j,m,t+1)
      //       vec.pb(j);
      // }
      // cout<<solve(n,vec);
   }
}