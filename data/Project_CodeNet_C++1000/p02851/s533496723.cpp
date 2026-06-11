/*
s[r] - s[l] = r - l (mod k)
s[r] - r = s[l] - l (mod k)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200010;

int n, k;
ll s[N];
map<ll,ll>S;

int main() {
	cin >> n >> k;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	S[0] = 1;
	ll ans = 0;
	int l = 0;
//	for(int i = 1; i <= n; ++i) printf("%d ", (s[i] - i + k) % k);
//	puts("");
	for(int i = 1; i <= n; ++i) {
		if(i >= k) {S[(s[l] - l + k) % k]--; ++l;}
		ans += S[(s[i] - i + k) % k];
//		printf("%d ", S[(s[i] - i + k) % k]);
		S[(s[i] - i + k) % k]++;
	}//puts("");
	printf("%lld\n", ans);
	return 0;
}