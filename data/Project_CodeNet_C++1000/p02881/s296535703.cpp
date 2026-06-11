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
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	long long int ans = 0;
	long long int n, m = LINF;
	cin >> n;
	for (int i = 1; i < sqrt(n) + 1; i++) {
		if (n % i == 0) {
			if (i + n / i < m) {
				m = i + n / i;
			}
		}
	}
	cout << m - 2 << endl;
	return 0;
}