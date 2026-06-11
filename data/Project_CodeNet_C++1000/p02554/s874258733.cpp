#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[1000006];
ll Mod(ll x, ll y, int p) 
{ll res = 1; x = x % p;
while (y > 0) 
{if(y & 1) res = (res*x) % p; 
y = y>>1;x = (x*x) % p; 
}return res; 
}
int main(){
	 int n;
	 cin>>n;
	 if(n == 1){
	 	cout<<"0"<<endl;
	 }
	 else if(n == 2){
	 	cout<<"2"<<endl;
	 }
	 else{
	 	   
         ll ans = ((Mod(10 , n , mod)%mod)+ Mod(8 , n , mod)- (2*Mod(9 , n , mod))%mod + mod)%mod;
         cout<<ans<<endl;
	 }
}