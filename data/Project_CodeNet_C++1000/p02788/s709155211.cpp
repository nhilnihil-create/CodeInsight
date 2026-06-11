#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long sum[200020] = { 0 };
vector<pair<long long,long long>> vec;
long long here[200020];
int main() {
	long long n, d, a, x, h;
	cin >> n >> d >> a;
	for (int i = 0; i < n; i++) {
		cin >> x >> h;
		vec.emplace_back(make_pair(x, h));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		pair<long long, long long> p = make_pair(vec[i].first + 2 * d, 1000000007);
		auto itr = upper_bound(vec.begin(), vec.end(), p);
		here[i] = itr - vec.begin();
	}
	long long num = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		num += sum[i];
		if (vec[i].second - num > 0) {
			long long co = ((vec[i].second - num) + a - 1) / a;
			ans += co;
			num += co * a;
			sum[here[i]] -= co * a;
		}
	}
	cout << ans << endl;
}
