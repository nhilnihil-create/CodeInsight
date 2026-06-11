#include<bits/stdc++.h>
using namespace std;
int mod;
int ksm(int b,int n){
	int res=1;
	while(n){
		if(n&1) res=1ll*res*b%mod;
		b=1ll*b*b%mod; n>>=1;
	}
	return res;
}
int f[2][105][105],pw[105][10005],C[105][105];
void init(int n){
	for(int i=0;i<=n;++i){
		pw[i][0]=1;
		for(int j=1;j<=n*n;++j)
			pw[i][j]=1ll*pw[i][j-1]*i%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
void add(int &x,int y){
	x=(x+y)%mod;
}
signed main(){
	int m,d;
	cin>>m>>d;
	int ans=0;
	for(int i=10;i<=d;++i){
		if(i%10<2 || i/10<2) continue;
		int tmp=(i%10)*(i/10);
		if(1<=tmp&&tmp<=m) ++ans;
	}
	cout<<ans;
	return 0;
}
