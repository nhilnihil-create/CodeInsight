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
	int n, m = 0;;
	bool f = 1;
	cin >> n;
	vector<int> h(n);
	//vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> h.at(i);
		if (h.at(i) > m)m = h.at(i);
		if (m - h.at(i) >= 2)f = 0;
	}
	if (f == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}