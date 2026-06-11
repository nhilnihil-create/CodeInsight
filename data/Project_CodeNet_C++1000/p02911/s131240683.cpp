#include <iostream>
using namespace std;

const int mxN = 1e5 + 5;
int cnt[mxN], a[mxN];
bool answer[mxN];

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) {
		cnt[i] = k;
		answer[i] = true;
	}
	int tot = 0;
	while(q--) {
		int x;
		cin >> x;
		if(cnt[x] - tot <= 0)
			answer[x] = false;
		++cnt[x];
		++tot;
	}
	for(int i = 1; i <= n; ++i) {
		if(cnt[i] - tot <= 0)
			answer[i] = false;
		cout << (answer[i] ? "Yes" : "No") << '\n';
	}
}
