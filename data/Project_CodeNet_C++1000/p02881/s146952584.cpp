#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n;
vector <int> v;

void check(int a, int b) {
	if (a*b == n) v.push_back(a+b-2);
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= sqrt(n); ++i) {
		check(i, n/i);
	}
	cout << *min_element(v.begin(), v.end());
}