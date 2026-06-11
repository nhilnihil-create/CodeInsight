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
	int n;
	int m = 0;
	cin >> n;
	vector< int> a(n+1),b(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	a.at(n) = INF;
	for (int i = n - 1; i >= 0; i--) {
		if (a.at(i + 1) <= a.at(i))b.at(i) = b.at(i + 1) + 1;
	}
	for (int i = 0; i < n; i++) {
		if (b.at(i) > m)m = b.at(i);
	}
	cout << m << endl;
	return 0;
}