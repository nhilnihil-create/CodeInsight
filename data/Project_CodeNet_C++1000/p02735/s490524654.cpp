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
#define mod 1000000007
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
	ll n , m ;
	cin>> n >> m ;
	char arr[n][m];
	ll dp[n][m];
	memset(dp , 0, sizeof dp);
	for(ll i=0;i<n ;i++){
		for(ll j=0;j<m ; j++){
			cin>>arr[i][j];
		}
	}
	if(arr[0][0]=='#'){
		dp[0][0]=1;
	}
	else dp[0][0]=0;
	for(ll i=1;i<n ;i++){
		dp[i][0] = arr[i][0]=='#' && arr[i-1][0]=='.'? dp[i-1][0]+1 : dp[i-1][0];
	}
	for(ll i=1;i<m ;i++){
		dp[0][i] = arr[0][i]=='#' && arr[0][i-1]=='.' ? dp[0][i-1]+1 : dp[0][i-1];
	}
	for(ll i=1;i<n ;i++){
		for(ll j= 1 ; j<m ; j++){
			ll a =0 , b=0;
			if(arr[i][j]=='#'){
				if(arr[i-1][j]=='.')a=1;
				if(arr[i][j-1]=='.')b=1;
			}
			dp[i][j]=min(dp[i-1][j]+a , dp[i][j-1]+b);
		}
	}
	
	cout<<dp[n-1][m-1]<<endl;
}
int main(){
	//mahakal(),fast;
	solve();

	return 0;
}