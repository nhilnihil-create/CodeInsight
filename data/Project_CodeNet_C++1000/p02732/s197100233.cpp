#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
ll nc2[N+100];
int cnt[N+100],a[N+100];

int main()
{
	for(int i=0;i<=N;i++){
		nc2[i] = 1ll*i*(i-1);
		nc2[i]/=2;
	}
	int n;
	scanf("%d",&n);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		ans += nc2[cnt[i]];
	}
	for(int i=1;i<=n;i++){
		int cur = cnt[a[i]];
		printf("%lld\n",ans-nc2[cur]+nc2[cur-1]);
	}
}
