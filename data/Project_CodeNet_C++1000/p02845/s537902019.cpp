#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n;
	cin >> n;
	int a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int ans = 1;
	long long int cnt[100000] = {};
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			ans = (ans * max((long long int)0, 3 - cnt[a[i]])) % mod;
		else
			ans = (ans * max((long long int)0, (cnt[a[i] - 1] - cnt[a[i]]))) %
			      mod;
		cnt[a[i]]++;
	}

	cout << ans << endl;
}