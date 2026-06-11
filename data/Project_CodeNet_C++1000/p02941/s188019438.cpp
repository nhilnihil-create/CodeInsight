#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[200005],b[200005];
queue <int> q;

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&b[i]);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=n;i++) {
  	if (a[i]<b[i]) {
  		puts("-1");
  		return 0;
	  }
    if (a[i]!=b[i]) q.push(i);
  }
  ll ans=0;
  while (!q.empty()) {
  	int x=q.front();q.pop();
  	int l=((x>1)?x-1:n),r=((x<n)?x+1:1);
  	if (a[x]<a[l]+a[r]||a[x]==b[x]) continue;
  	if (b[x]>=a[l]+a[r]&&a[x]%(a[l]+a[r])!=b[x]%(a[l]+a[r])) {
  		puts("-1");
  		return 0;
	  }
	if (b[x]>=a[l]+a[r]) {
		ans+=(a[x]-b[x])/(a[l]+a[r]);
		a[x]=b[x];
	}
	else {
		ans+=a[x]/(a[l]+a[r]);
		a[x]%=(a[l]+a[r]);
		if (a[x]<b[x]) {
			puts("-1");
			return 0;
		}
	}
	q.push(l);q.push(r);
  }
  for(int i=1;i<=n;i++)
    if (a[i]!=b[i]) {
    	puts("-1");
    	return 0;
	}
  printf("%lld\n",ans);
  return 0;
}