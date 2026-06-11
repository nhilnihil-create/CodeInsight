#include <bits/stdc++.h>
using namespace std;
 
 string arr;
 int len;
 const int  mod = 1e9+7;
long long dp[100001][14][2];

long long back(int in, int num , bool flag  ){
	
 	if(in> len) {   if(num%13==5) return 1; else return 0; }
 	
 	if(dp[in][num][flag]!=-1)	return dp[in][num][flag];
 	
 	long long res=0;
 	
 	
 	if(arr[in-1]!='?')  res=back(in+1, ( num*10 + (arr[in-1]-'0') )%13 ,flag)%mod;
 	
 	else {
	 	 int limit = 9;
	 	 
	 	for(int i=0; i<=limit; ++i){
	 	res+= (back(in+1, (10*num + i)%13, flag || i<limit)%mod);		
	 	res%=mod;
	 	}
 	}
 	return dp[in][num][flag] = res%mod;
 }
 
 
 
int main() {
	

	cin>>arr;
	len = arr.size();
	memset(dp, -1, sizeof dp);
	 
	 long long c= back(1,0,false)%mod + mod;
	 c%=mod;
	 cout<<  c <<'\n'; 
	return 0;
}
