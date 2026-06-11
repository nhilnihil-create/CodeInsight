#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,from,to) for(int i=from; i<to; ++i)
#define REP(i,from,to) for(int i=from; i<=to; ++i)
using namespace std;

const int MAXN = 250000;
bool p[MAXN];
int n;

void maketbl() {
	for (int i = 0; i < MAXN; ++i) {
		p[i] = false;
	}
	p[0] = p[1] = true;
	for (int i = 2; i < MAXN; ++i) {
		if (p[i]) {
			continue;
		}
		for (int j = i * 2; j < MAXN; j += i) {
			p[j] = true;
		}
	}
}

void solve() {
	while (cin >> n, n) {
		int ans = 0;
		REP(i,n+1,2*n)
		{
//			printf("%2d: %d\n", i, p[i]);
			if (!p[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}

int main() {
	maketbl();
	solve();
}