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

typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN 200100

vector<int> a;
int ms[MAXN];
set<int> s;

int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
		ms[t]++;
		s.insert(t);
	}
	ll ans = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		int cur = *it;
		int num = ms[cur];
		ans += ((ll)(num) * (num - 1)) / 2;
	}
	for (int i = 0; i < n; i++) {
		printf("%lld\n", ans - ms[a[i]]  + 1);
	}
	return 0;
}
