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

#include <atcoder/all>
using namespace atcoder;

using namespace std;

long long n;
vector<long long> BIT(500050);
void add(long long i, long long x) {
	while (i <= n) {
		BIT[i] += x;
		i += i & -i;
	}
}
long long csum(long long i) {
	long long count = 0;
	while (i > 0) {
		count += BIT[i];
		i -= i & -i;
	}
	return count;
}
long long sum(long long l, long long r) {
	return csum(r) - csum(l - 1);
}
int main() {
	int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		add(i, a);
    }
	for (int i = 0; i < q; i++) {
		int b, l, r;
		cin >> b >> l >> r;
		if (b == 0) {
			add(l + 1, r);
		}
		else {
			cout << sum(l + 1, r) << endl;
		}
	}
    return 0;
}
