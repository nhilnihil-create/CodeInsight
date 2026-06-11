#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
ll x, k, d, t, ans;
int main(){
	scanf("%lld%lld%lld", &x, &k, &d);
	x = abs(x);
	t = x / d;
	if(k < t) ans = x - d*k;
	else{
		k -= x / d;
		x %= d;
		ans = k & 1 ? d - x : x;
	}
	printf("%lld\n", ans);
}