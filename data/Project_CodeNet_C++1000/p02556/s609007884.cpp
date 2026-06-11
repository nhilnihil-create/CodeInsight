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
	int N;
	cin>>N;
	int amin=2e9,amax=-2e9,bmin=2e9,bmax=-2e9;
	for(int i=1;i<=N;++i){
		int a,b;
		cin>>a>>b;
		amin=min(amin,a+b);
		amax=max(amax,a+b);
		bmin=min(bmin,a-b);
		bmax=max(bmax,a-b);
	}
	int ans=max(max(amax-amin,bmax-bmin),max(bmax-bmin,amax-amin));
	cout<<ans<<endl;
	return 0;
}
