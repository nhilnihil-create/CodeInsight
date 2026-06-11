#include<bits/stdc++.h>
#define ROCK 0
#define SCISSORS 1
#define PAPER 2
using namespace std;
int n,k,r,s,p;
string arr;
int dp[100005][4];
int f(int curr,int shape){
	if(curr>=n) return 0;
	int&ret=dp[curr][shape];
	if(~ret) return ret; 
	for(int i=0; i<3; i++){
		if(i!=shape) ret = max(ret,f(curr+k,i));
	}
	if(arr[curr]=='p') ret+=(shape==SCISSORS?s:0);
	else if(arr[curr]=='s') ret+=(shape==ROCK?r:0);
	else ret+=(shape==PAPER?p:0);
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>k>>r>>s>>p;
	cin>>arr;
	int ret = 0;
	for(int i=0; i<k; i++){
		int mx = 0;
		for(int j=0; j<3; j++){
			mx = max(mx,f(i,j));
		}
		ret+=mx;
	}
	cout<<ret; 
}
