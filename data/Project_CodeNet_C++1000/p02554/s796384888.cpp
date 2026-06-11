#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod=1e9+7;
const int INF=0x3f3f3f3f;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL N,a=10,b=9,c=8;
	cin>>N;
	while(--N){
		a=a*10%Mod;
		b=b*9%Mod;
		c=c*8%Mod;
	}
	b=b*2%Mod;
	LL ans=(a-b+c)%Mod;
	if(ans<0) ans+=Mod;
	cout<<ans<<endl;
	return 0;
}
