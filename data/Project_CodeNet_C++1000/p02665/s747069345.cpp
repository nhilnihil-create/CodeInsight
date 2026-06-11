//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_d
#include<bits/stdc++.h>
using namespace std;
#define nn 65536*16
#define int long long

int cnt[nn],n,suf[nn];
int ans=0;

void dfs(int x,int now){
	ans+=now;//cout<<now<<"\n";
	if(x==n) {
		if(cnt[x]!=now) ans=-1;
		return ;	
	}
	now-=cnt[x];if(now<=0) {
		ans=-1;return ;
	}
	dfs(x+1,min(now*2,suf[x+1]));
}

signed main(){
	scanf("%lld",&n);for(int i=0;i<=n;i++) scanf("%lld",&cnt[i]),suf[i]=cnt[i];
	for(int i=n;i>=0;i--) suf[i]+=suf[i+1];
	dfs(0,1);
	printf("%lld\n",ans);	
	return 0;
} 