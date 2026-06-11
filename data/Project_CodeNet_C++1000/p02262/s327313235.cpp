#include <iostream>

#define rep(i, first, to) for(ll i = first; i < to; ++i)
#define REP(i, first, to) for(ll i = first; i <= to; ++i)

using namespace std;
typedef long long ll;

int cnt = 0;
int a[1000001];
int n;
int g[1000001];

void show(int *p) {
	rep(i, 0, n - 1) {
		cout << p[i] << " ";
	}
	cout << p[n - 1] << endl;
}

void insertSort(int g) {
	//cout << "now" << g << endl;
	for (int i = g; i < n; ++i) {
		int v = a[i];
		int j = i - g;
		for (;j >= 0 && a[j] > v; j -= g) {
			a[j + g] = a[j];
			++cnt;
		}
		a[j + g] = v;
		//show(a);
	}
}

void shellSort() {
	int m = 0;
	for(int i = 0; 3 * g[m - 1] + 1 <= n; m++) {
		g[m] = 3 * g[m - 1] + 1;
	}
	for (int i = m - 1; i >= 0; --i) {
		insertSort(g[i]);
		//show(a);
	}
	//show(a);
	cout << m << endl;
	for (int i = m - 1; i > 0; --i) {
		cout << g[i] << " ";
	}
	cout << g[0] << endl;
	cout << cnt << endl;
	rep(i, 0, n) {
		cout << a[i] << endl;
	}
}

void solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
	}
	shellSort();
}

int main() {
	solve();
	return 0;
}