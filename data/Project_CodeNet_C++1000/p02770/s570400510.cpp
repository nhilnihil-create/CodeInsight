#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int k, q, i;
	scanf("%lld%lld", &k, &q);
	vector<int> d(k);
	for(i = 0; i < k; i++){
		scanf("%d", &d[i]);
	}
	while(q--){
		int n, x, m, ans = 0, s = 0, a_last;
		scanf("%lld%lld%lld", &n, &x, &m);
		x %= m;
		a_last = x;
		vector<int> d_mod_m(k);
		for(i = 0; i < k; i++){
			d_mod_m[i] = d[i] % m;
			s += d_mod_m[i];
		}
		for(i = 0; i < k; i++){
			if(d_mod_m[i] == 0){
				ans += (n - 1) / k + ((n - 1) % k > i ? 1 : 0);
			}
			a_last += d_mod_m[i] * ((n - 1) / k + ((n - 1) % k > i ? 1 : 0));
		}
//		printf("ans1 = %lld\n", ans);
//		printf("a_last = %lld\n", a_last);
		ans += a_last / m;
		printf("%lld\n", n - 1 - ans);
	}
	return 0;
}