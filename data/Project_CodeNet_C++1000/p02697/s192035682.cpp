#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FRE freopen("in.txt", "r", stdin);
#define endl "\n"
#define PI acos(-1.0)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int N = 110, M = 1010;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x = (n + 1) / 2, y = x + 1, cnt = m;
	for(int i = 1; i <= m; i++) {
		if(i & 1) {
			printf("%d %d\n", x - cnt, x);
			cnt--;
			x--;
		}
		else {
			printf("%d %d\n", y, y + cnt);
			cnt--;
			y++;
		}
	}
}

int main() {
	//FRE;
	int t;
	solve();
	return 0;
}
