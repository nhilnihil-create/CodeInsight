#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e6 + 1;
bool sieve[sz], f;
int cnt[sz], num[sz];

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void func(int n) {
	int d = 2, pre = 0;
	while (sieve[n]) {
		if (n % d == 0) {
			n /= d;
			if (pre != d) {
				if (++cnt[d] > 1) f = true;
				pre = d;
			}
		}
		else d++;
	}

	if (n != 1) {
		if (pre != n) {
			if (++cnt[n] > 1) f = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;

	for (int i = 2; i < sz; i++) {
		if (sieve[i]) continue;
		for (int j = i + i; j < sz; j += i) sieve[j] = true;
	}

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		func(num[i]);
	}

	if (!f) cout << "pairwise coprime";
	else {
		int g = num[0];
		for (int i = 1; i < N; i++) g = gcd(g, num[i]);
		if (g == 1) cout << "setwise coprime";
		else cout << "not coprime";
	}
}