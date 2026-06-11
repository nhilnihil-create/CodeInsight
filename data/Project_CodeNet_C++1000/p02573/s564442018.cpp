#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 200007
#define MO (int(1e9)+7)
int f[MAXN];
int cnt[MAXN];
inline int findf(int x) {
	int ff=x;
	while(f[ff]!=ff) ff=f[ff];
	while(x!=ff) {
		int t=f[x];
		f[x]=ff;
		x=t;
	}
	return ff;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=0; i<m; i++) {
		int a,b; cin>>a>>b;
		int f1=findf(a), f2=findf(b);
		f[f1]=f2;
	}
	memset(cnt,0,sizeof cnt);
	int ans=0;
	for(int i=1; i<=n; i++) {
		int fi=findf(i);
		cnt[fi]++;
		ans = max(ans, cnt[fi]);
	}
	cout << ans << '\n';
}
