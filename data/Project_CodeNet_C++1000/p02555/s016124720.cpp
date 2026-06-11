#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod=1e9+7;
const int INF=0x3f3f3f3f;
//组合数 
const int __Mod=1e9+7;
int C[100000][2000];
void init(int n,int m){
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i && j<=m;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1]) %__Mod;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s;
	cin>>s;
	int limit=s/3;
	init(s,limit);
	LL ans=0;
	for(int i=1;i<=limit;++i){
		ans=(ans+C[s-2*i-1][i-1]%Mod)%Mod;
	}
	cout<<ans<<endl;
	return 0;
}
