#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll BASE = 1000000000;

int main() {
	ll S; scanf("%lld", &S);
	ll cont1 = S / BASE + (S % BASE == 0 ? 0 : 1);
	ll cont2 = cont1 * BASE - S;
	printf("0 0 %lld %lld 1 %lld\n", BASE, cont2, cont1);
}
