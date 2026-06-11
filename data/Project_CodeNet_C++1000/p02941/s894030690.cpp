#include <bits/stdc++.h>
using namespace std;
#define nn 300008
#define int long long 
#define mod 998244353
int ai[nn],bi[nn];int n;
signed main() {
	#define a ai
	#define b bi
	scanf("%lld",&n);for(int i=1;i<=n;i++) scanf("%lld",&ai[i]);for(int i=1;i<=n;i++) scanf("%lld",&bi[i]);
	#define pii pair<int,int>
	#define mp make_pair
	set<pii> s;for(int i=1;i<=n;i++) s.insert(mp(bi[i],i));
	int ans=0;
	while(s.size()){
		int x=(*s.rbegin()).second;s.erase(--s.end());
		if(b[x]==a[x]) continue;
		if(b[x]<a[x]) break;
		b[0]=b[n],b[n+1]=b[1];
		int su=b[x-1]+b[x+1],dif=b[x]-a[x];
		if(dif<su) break;
		ans+=dif/su,dif%=su;
		b[x]=a[x]+dif;
		s.insert(mp(b[x],x));
	}
	
	for(int i=1;i<=n;i++) if(ai[i]!=bi[i]) return puts("-1")*0;
	cout<<ans;
	return 0;
}

