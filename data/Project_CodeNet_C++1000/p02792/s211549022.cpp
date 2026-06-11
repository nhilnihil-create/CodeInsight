#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

P split(int x)
{
	int a = x % 10;
	int b = 0;
	while (x > 0) {
		b = x;
		x /= 10;
	}
	return make_pair(a, b);
}

int main()
{
	int n;
	cin >> n;
	
	map<P, int> freq;
	for (int i = 1; i <= n; ++i) {
		P p = split(i);
		freq[p]++;
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		P p = split(i);
		P q = make_pair(p.second, p.first);
		ans += freq[q];
	}

	cout << ans << endl;
	return 0;
} 