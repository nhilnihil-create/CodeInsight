#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long tenth[100005];
vector<long long>question;
long long dp[13][100005];

long long f(int r,int curr){
	if(curr>=question.size()) return (r==0);
	long long&ret = dp[r][curr];
	if(~ret) return ret;
	ret = 0;
	for(int i=0; i<10; i++){
		int x = question[curr]*i;
		x%=13;
		ret+=f((13+r-x)%13,curr+1);
		ret%=mod;
	}
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	int r = 0;
	tenth[0] = 1;
	for(int i=0; s[i]; i++){
		if(i==0){
			if(s[i]=='?') continue;
			r+=(int)(s[i]-'0');
		}
		else{
			tenth[i] = 10*tenth[i-1];
			tenth[i]%=13;
			if(s[i]=='?') continue;
			r+=tenth[i]*(int)(s[i]-'0');
			r%=13;
		}
	}

	r = (18-r)%13;
	for(int i=0; s[i]; i++){
		if(s[i]=='?') question.push_back(tenth[i]);
	}
	cout<<f(r,0);
}