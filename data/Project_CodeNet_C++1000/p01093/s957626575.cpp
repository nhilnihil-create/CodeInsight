#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 1000000
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int a[1000];
		for (int i = 0;i < n;i++)cin >> a[i];
		sort(a, a + n);
		int ans=INF ;
		for (int i = 0;i < n - 1;i++) {
			int b = a[i + 1] - a[i];
			if (ans > b)ans = b;
		}
		cout << ans << endl;
	}
	return 0;
}