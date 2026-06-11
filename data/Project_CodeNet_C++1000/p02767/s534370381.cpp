#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1e6;
int n, a[N]; 

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= 100; i++) {
		int tmp = 0;
		for(int j = 1; j <= n; j++) {
			tmp += (a[j] - i) * (a[j] - i);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
} 