#include <bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	const int mod=1e9+7;
	auto mul=[&](int a,int b){return 1LL*a*b%mod;};
	auto fail=[](){cout<<"0\n";exit(0);};
	int n;
	string s;
	cin>>n>>s;
	if(s[0]=='W')fail();
	if(s[2*n-1]=='W')fail();
	vector<char>tmp(2*n);
	tmp[0]='(';
	for(int i=1;i<2*n;i++){
		if(s[i]==s[i-1]){
			if(tmp[i-1]=='(')tmp[i]=')';
			else tmp[i]='(';
		}
		else {
			if(tmp[i-1]=='(')tmp[i]='(';
			else tmp[i]=')';
		}
	}
	int cnt=0;
	int ans=1;
	for(int i=0;i<2*n;i++){
		if(tmp[i]=='(')cnt++;
		else {
			if(cnt==0)fail();
			ans=mul(ans,cnt);
			cnt--;
		}
	}
	if(cnt!=0)fail();
	for(int i=2;i<=n;i++){
		ans=mul(ans,i);
	}
	cout<<ans<<'\n';
	return 0;
}