#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	ll ans = 1ll * n * (n + 1) * (n + 2) / 6;
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		if (u > v) swap(u , v);
		ans -= 1ll * u * (n - v + 1);
	}
	printf("%lld\n" , ans);
}