#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t GCD(int64_t a, int64_t b) {
	if (!b) return a;
	else return GCD(b, a % b);
}

int main() {
	int64_t A, B;
	cin >> A >> B;

	int64_t gcd = GCD(A, B);
	vector<pair<int64_t, int64_t>> v;

	int64_t rt = sqrt(gcd), n = gcd;
	for (int64_t i = 2; i <= rt; i++) {
		int64_t c = 0;
		while (n % i == 0) {
			if (n / i == 0) break;
			else {
				c++;
				n /= i;
			}
		}
		if (c) {
			pair<int64_t, int64_t> p = { i,c };
			v.push_back(p);
		}
	}
	if (n>1) {
		pair<int64_t, int64_t> p = { n,1 };
		v.push_back(p);
	}

	cout << v.size() + 1 << endl;
}