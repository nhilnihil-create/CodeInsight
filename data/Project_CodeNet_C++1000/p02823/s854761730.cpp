# include <iostream>
# include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll N, A, B; scanf("%lld%lld%lld", &N, &A, &B);
	ll diff = B - A;

	ll ans;
	if ((diff & 1) == 0) ans = diff / 2;
	// 差が奇数の時、近い方が端へ行き、一度戦った後、近づく
	else {
		ll distance = min(A, N - B + 1);
		ans = distance + (diff - 1) / 2;
	}

	printf("%lld\n", ans);
	return 0;
}