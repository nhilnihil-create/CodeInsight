#include <bits/stdc++.h>
using namespace std;

#define SIZE (long long)1000000000
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long S;
	scanf("%lld", &S);

	long long h = (S - 1) / SIZE + 1;
	long long w = h * SIZE - S;
	// printf("h = %lld w = %lld\n", h, w);
	printf("%lld %lld %lld %lld %lld %lld", (long long)0, (long long)0, w, h,
	       SIZE, (long long)1);

	return 0;
}