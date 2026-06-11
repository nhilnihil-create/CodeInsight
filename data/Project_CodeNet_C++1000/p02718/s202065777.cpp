#include <iostream>
#include <math.h>
#include <map>
using namespace std;

const int mxN = 1e2 + 5;
int a[mxN];

int main() {
	int n, m;
	cin >> n >> m;
	int tot = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], tot += a[i];
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt += (a[i] * 4 * m >= tot);
	cout << (cnt >= m ? "Yes" : "No");
}
