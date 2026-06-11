#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
vector<ll> dp;
int main(){
 ll n;
 cin>>n;
 dp.resize(n+1);
 for(ll i=3;i<=n;i++){
 	dp[i]+=1;
 	for(ll j=3;j<=i-3;j++){
 		dp[i]+=dp[j];
		dp[i]%=M; 	
	}
 }
 cout<<dp[n]<<endl;
 return 0;
}

