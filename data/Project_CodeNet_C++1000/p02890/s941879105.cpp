#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[300005];
int cnt[300005],qzh[300005];

signed main() {
	scanf("%lld",&n);
	for(int i=0; i<n; i++) {
		scanf("%lld",a+i);
		cnt[a[i]]++;
	}
	sort(cnt,cnt+n+1);
	for(int i=1; i<=n; i++) {
		qzh[i]=qzh[i-1]+cnt[i];
	}
	for(int i=1; i<=n; i++) {
		int ff=n/i;
		if(cnt[n]<=ff) {
			printf("%lld\n",ff);
		} else {
			int l=0,r=n+1;
			while(r-l>1) {
				int m=(l+r)>>1;
				int now=upper_bound(cnt,cnt+n+1,m)-cnt;
				int num=qzh[now-1]+(n-now+1)*m;
				if(num>=i*m) {
					l=m;
				} else {
					r=m;
				}
			}
			printf("%lld\n",l);
		}
	}
	return 0;
}
