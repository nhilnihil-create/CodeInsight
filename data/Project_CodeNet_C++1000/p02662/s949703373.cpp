// Winners don't quit and Quitters don't win
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mod 998244353
#define MAX 100005
 
int main()
{
 
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int x,n,s,i,j;
    vii v;
    cin>>n>>s;
    int dp[n+1][s+1];
    for(i=0;i<n;++i){
    	cin>>x;
    	v.pb(x);
    }
    for(i=0;i<=n;++i){
    	for(j=0;j<=s;++j){
    		dp[i][j]=0;
    	}
    }
    // base case
    dp[0][0]=1;
    
    for(i=0;i<n;++i){
    	for(j=0;j<=s;++j){
    		// first choice that we don't take the ith element
    		dp[i+1][j] = (dp[i+1][j] + ((2 % mod * dp[i][j] % mod) % mod)) % mod;
            dp[i+1][j] %= mod;
           // second choice that we take the ith element into the subset which contains sum j 
    	   // the resultant subset will be of sum previous subset sum + v[i]
    		if((j + v[i]) <= s){
               dp[i+1][j + v[i]] = (dp[i+1][j + v[i]] + dp[i][j]) % mod;
    		}
    		// here when we take extra one element the number of subsets which will contain this subset
    		// will be half of what it was for previous subset
    	}
    }
    cout<<dp[n][s];
}