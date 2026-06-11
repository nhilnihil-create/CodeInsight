#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	int n, k;
	vector<ll> a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll ret = 0;
	for (int i = min(k, n); i < n; i++) {
		ret += a[i];
	}
	cout << ret << endl;

	return 0;
}
