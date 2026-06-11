#include <bit>
#include <bitset>
#include <assert.h>
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

#define MAXN (1 << 20)

ll a[MAXN];
ll n, k;
multiset<ll> s;
ll ss[MAXN];

map<int, int> cnt;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = (a[i] + k - 1) % k;
	}
	ll sum = 0;
	cnt[0]++;	
	ll ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += a[i];
		sum %= k;
		ss[i] = sum;
		if (i + k <= n) {
			cnt[ss[i + k]]--;
		}
		//cerr << s.count(sum);
		ret += cnt[sum];
		cnt[sum]++;
	}
	cout << ret << endl;
	return 0;
}
