#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
int main(){
	int ans=1001;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<sz(s)-sz(t)+1;i++){
		int c=0;
		for(int j=0;j<sz(t);j++){
			c+=(s[i+j]!=t[j]);
		}
		ans=min(ans,c);
	}
	cout<<ans;
}
