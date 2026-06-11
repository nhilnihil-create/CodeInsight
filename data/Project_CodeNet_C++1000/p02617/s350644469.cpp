#include<bits/stdc++.h>
using namespace std;

#define i64 long long int
#define ran 202202

int n;

i64 ans;

int main() {
	scanf("%d", &n);
	ans = 0;
	for(int i=1;i<=n;i++)
		ans += 1LL * i * (n-i+1);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		if(x>y) swap(x, y);
		ans -= 1LL*x*(n-y+1);
	}
	printf("%lld\n", ans);
	
	return 0;
}