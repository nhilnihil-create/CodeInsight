#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define dow(i,j,k) for (int i = j; i >= k; i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int n;
int main() {
	scanf("%d", &n);
	if ((!(n & (n - 1)))) return puts("No"), 0;
	puts("Yes");
	int m = n;
	if (n % 2 == 0) m--;
	printf("%d %d\n", n + 1, 3);
	for (int i = 2; i < m; i += 2) {
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", i, 1);
		printf("%d %d\n", i + n + 1, i + n);
		printf("%d %d\n", i + n + 1, 1);
	}
	if (n % 2 == 0) {
		int x = n & -n;
		int y = n - x;
		printf("%d %d\n", n, x);
		printf("%d %d\n", y + n + 1, n * 2);
	}
	return 0;
}
		