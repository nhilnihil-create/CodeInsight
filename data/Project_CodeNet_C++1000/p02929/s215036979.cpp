#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7,N=2e5+5;
char s[N];int n,a[N];
signed main(){
	cin>>n>>(s+1);
	n<<=1;
	int res=0;
	for(int i=1;i<=n;++i){
		a[i]=(res&1)^(s[i]=='W');
		res+=(a[i]==1?-1:1);
		if(res<0) return puts("0"),0;
	}
	if(res) return puts("0"),0;
	int ans=1;
	for(int i=1;i<=n;++i){
		if(a[i]==1) ans=ans*res%mod,res--;
		else ++res;
	}
	for(int i=1;i<=n/2;++i)
		ans=ans*i%mod;
	cout<<ans;
	return 0;
}