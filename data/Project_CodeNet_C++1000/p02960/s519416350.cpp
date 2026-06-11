#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007;
void solve(){
string s;
cin>>s;
long long n=s.size();
unordered_map<long long,unordered_map<long long,long long>> dp;
if(s[0]=='?'){
	for(long long i=0;i<10;i++){
		dp[0][i]=1;
	}
}
else{
dp[0][s[0]-'0']=1;

}
for(long long i=1;i<n;i++){
	long long c;
	if(s[i]=='?'){
		c=-1;
	}
	else{
	c=s[i]-'0';
	}
	for(long long j=0;j<10;j++){
		if(c!=-1&&c!=j){
			continue;
		}
		for(long long k=0;k<13;k++){
			dp[i][(10*k+j)%13]+=dp[i-1][k];
		}
	}
	for(long long j=0;j<13;j++){
		dp[i][j]=dp[i][j]%MOD;
	}
	
}
cout<<dp[n-1][5];
}



int main() {
solve();


}

