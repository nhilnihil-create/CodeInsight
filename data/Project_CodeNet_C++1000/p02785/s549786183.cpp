#include <iostream>
#include <algorithm>
using namespace std;

const int mxN = 2e5 + 5;
int a[mxN];

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long long answer = 0;
	for(int i = n - 1; ~i; --i) {
		if(k) {
			--k;
			continue;
		}
		answer += a[i];
	}
	cout << answer;
}
