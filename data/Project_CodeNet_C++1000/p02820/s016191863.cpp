#include<bits/stdc++.h>
using namespace std;
int n,k;
int r,s,p;
string arr;
int dp[100005][3];
int cost[3];

int score(char ch,int num){
	if(ch=='r'){
		if(num<=1) return 0;
		return p;
	}
	else if(ch=='s'){
		if(num==0) return r;
		return 0;
	}
	else{
		if(num==1) return s;
		return 0;
	}
}
int f(int curr,int shape){
	if(curr>=n) return 0;
	int&ret = dp[curr][shape];
	if(~ret) return ret;
	ret = 0;
	for(int i=0; i<3; i++){
		if(i!=shape){
			ret = max(ret,f(curr+k,i));
		}
	}
	return ret+=score(arr[curr],shape);
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	cin>>r>>s>>p;
	cost[0] = r;
	cost[1] = s;
	cost[2] = p;
	cin>>arr;
	int ret = 0;
	for(int i=0; i<k; i++){
		int mx = 0;
		for(int j=0; j<3; j++) mx = max(mx,f(i,j));
		ret+=mx;
	}
	cout<<ret;
}