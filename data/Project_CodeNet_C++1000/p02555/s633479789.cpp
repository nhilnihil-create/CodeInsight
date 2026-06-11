#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fill(a,b) memset(a,b,sizeof(a))

#define f first
#define s second
#define pb push_back

#define inf 1e17
#define ninf -1*1e17
#define mod 1000000007
#define N 500005
#define Ns 5005

string s;
ll n,m,o,x,y,z,d,k,l,r;

ll dp[N];
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    ll ans=0;
	    cin>>n;
	    dp[0]=1;
	    for(int i=1;i<=n;i++){
	      for(int k=3;k<=i;k++){
	        dp[i]=(dp[i]+dp[i-k])%mod;
	      }
	    }
	    
	   // for(int i=0;i<=n;i++){
	   //     cout<<dp[i]<<" ";
	   // }
	   // cout<<"\n";
	    cout<<dp[n]<<"\n";
	    
	    
	}
	return 0;
}
