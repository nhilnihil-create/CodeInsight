#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	long long a, b, k;

	scanf("%lld %lld %lld", &a, &b, &k);

	if (k < a){
		printf("%lld %lld\n", a-k, b);
	} else if (k == a){
		printf("%lld %lld\n", 0LL, b);
	} else {
		printf("%lld %lld\n", 0LL, max(b-(k-a), 0LL));
	}

	return 0;
}