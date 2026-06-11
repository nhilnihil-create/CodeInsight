#include <iostream>
using namespace std;

const int mxN = 205;
int a[mxN], b[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i)
		cin >> b[i];
	int tot = 0;
	b[0] = b[n] = 1e9 + 9;
	for(int i = 1; i <= n; ++i)
		tot += min(b[i], b[i - 1]);
	cout << tot;
}
