#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;

bool sq(int n) {
	bool f = 0;
	for (int i = 0; i < sqrt(n) + 1; i++) {
		if (n == i * i)f = 1;
	}
	return f;
}
int main() {
	int a, b;
	int ans=INF+1;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % 2019 == 0) {
			ans = 0;
			cout << ans << endl;
			return 0;
		}
	}
	a = a % 2019;
	b = b % 2019;
	if (a >= b)ans = 0;
	else {
		for (int i = a; i <= b; i++) {
			for (int j = i ; j <= b; j++) {
				if (i!=j&&ans > (i * j) % 2019)ans = (i * j) % 2019;
			}
		}
	}
	cout << ans << endl;
}