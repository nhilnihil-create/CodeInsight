#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (b[lhs] != b[rhs])
			return b[lhs] > b[rhs];
		return lhs < rhs;
	}
};

set <int, cmp> alive;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

ll solve() {
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i])
			return -1;
		if (a[i] < b[i])
			alive.insert(i);
	}
	
	ll sol = 0;
	while (!alive.empty()) {
		int x = *alive.begin();
		alive.erase(x);
		int sum = b[(x + N - 1) % N] + b[(x + 1) % N];
		if (b[x] <= sum)
			return -1;
		int rem = b[x] % sum;
		if (a[x] >= rem) {
			if ((b[x] - a[x]) % sum)
				return -1;
			sol += (b[x] - a[x]) / sum;
			b[x] = a[x];
		}
		else {
			sol += b[x] / sum;
			b[x] = rem;
			alive.insert(x);
		}
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}