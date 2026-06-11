#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
int a[N+100],ind[N+100],vis[N+100];

int main()
{
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	int cur = 1;
	for(ll i=0;i<=k;i++){
		ind[i] = cur;
		if(i==k){
			printf("%d\n",cur);
			return 0;
		}
		if(vis[cur]){
			int sz = i-vis[cur];
			ll ext = k-vis[cur];
			//printf("%d %lld\n",sz,ext);
			printf("%d\n",ind[ext%sz+vis[cur]]);
			return 0;
		}
		vis[cur] = i;
		cur = a[cur];
	}
}
