/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂
                   
                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            
 
 */ 
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
#define mod 998244353
#define inf 100000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _it iterator
#define all(_x) _x.begin(),_x.end()
#define f first
#define s second
#define pb push_back
void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}

void solve(){
	ll n , s;
	cin>> n >> s ;
	vector<ll>arr(n+1,0);
	ll dp[n+1][s+1];
	for(ll i=1;i<=n ;i++)cin>>arr[i];
	for(ll i=0;i<=n ;i++){
		for(ll sum=0 ; sum<=s ;sum++){
			if(i==0)dp[i][sum]=0;
			if(sum==0)dp[i][sum]=1;
			if(i==0){
				continue;
			}
			if(arr[i]>sum)dp[i][sum]=(2*dp[i-1][sum])%mod;
			else{
				dp[i][sum]=(2*dp[i-1][sum]%mod + dp[i-1][sum-arr[i]]%mod)%mod;
				dp[i][sum]%=mod;
			}
		
		}
	}

	// ll ans=0;
	// for(ll i=1;i<=s ;i++)ans+=dp[n][i];
	// cout<<ans<<endl;
	cout<<dp[n][s]<<endl;
}
int main(){
	//mahakal(),fast;
	ll t=1 ;
	// cin>> t;
	while(t--)solve();

	return 0;
}