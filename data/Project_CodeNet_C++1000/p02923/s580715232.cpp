#include <iostream>
using namespace std;

const int mxN = 1e5 + 5;
int a[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int best = -1, cnt = 0;
	for(int i = n; i; --i) {
		if(a[i] >= a[i + 1])
			++cnt;
		else
			cnt = 1;
		best = max(best, cnt);
	}
	cout << best - 1;
}
