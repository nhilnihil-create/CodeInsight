#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int mn = 2e5 + 5;
const int mod = 998244353;

int n;
vector<int> g[mn];

int main() {
#ifdef LOCAL
	freopen("../1.txt", "r", stdin);
	freopen("../2.txt", "w", stdout);
	size_t bg = clock();
#endif
	scanf("%d", &n);
	int n1 = 1;
	while (n1 < n) n1 <<= 1;
	if (n1 == n) {
		puts("No");
		return 0;
	}
	if (n == 3) {
		puts("Yes\n"
		     "1 2\n"
		     "2 3\n"
		     "3 4\n"
		     "4 5\n"
		     "5 6");
		return 0;
	}
	n1 >>= 1;
	for (int i = 1; i < n1 - 1; i++) {
		g[i].pb(i + 1);
		g[i + n].pb(i + n + 1);
	}
	g[n1 - 1].pb(n + 1);
	g[n1 + n].pb(1);
	g[n1 + 1 + n].pb(n1 + n);
	g[n1 + 1].pb(1);
	g[n1].pb(n1 + 1);
	for (int i = n1 + 2; i <= n; i++) {
		g[i].pb(i - n1 + n);
		g[i + n].pb(i - 1);
	}
	puts("Yes");
	for (int i = 1; i <= 2 * n; i++) {
		for (auto &j:g[i])
			printf("%d %d\n", i, j);
	}
#ifdef LOCAL
	size_t ed = clock();
	printf("time: %f\n", (double) (ed - bg) / CLOCKS_PER_SEC);
#endif
	return 0;
}