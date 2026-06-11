#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
string s;

int f(int start,int fin){
	int&ret = dp[start][fin];
	if(~ret) return ret;
	ret = 0;
	if(start==fin || start>fin) return ret;
	if(s[start]==s[fin]) return ret = f(start+1,fin-1);

	return ret = 1+f(start+1,fin-1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>s;
	int n = s.length()-1;
	cout<<f(0,n);
}