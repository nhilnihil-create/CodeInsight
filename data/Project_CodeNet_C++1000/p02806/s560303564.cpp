#include<bits/stdc++.h>
#define int long long
#define re register
using namespace std;
#define gc getchar
string s[1002],t;
int n,sum[1002],ans;
bool add;
signed main(){
	cin>>n;
	for(re int i=1;i<=n;++i){
		cin>>s[i]>>sum[i];
	}
	cin>>t;
	for(re int i=1;i<=n;++i){
		ans+=sum[i]*add;
		if(s[i]==t)add=1;
	}
	cout<<ans;
	}

