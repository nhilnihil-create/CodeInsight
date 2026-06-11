#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

const int N = 3e5 + 7;

int cnt[N];
int ps[N + 1];
int f[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	sort(cnt, cnt + N);
	for (int i = 0; i < N; i++) {
		ps[i + 1] = ps[i] + cnt[i];
	}
	for (int i = 1; i < N; i++) {
		//select i arrays 
		//sum(min(cnt[j], i)) / i
		int cntl = lower_bound(cnt, cnt + N, i) - cnt;
		f[i] = (ps[cntl] + (N - cntl) * i) / i;
	}
	//f[x] > f[x + 1]
	for (int k = 1; k <= n; k++) {
		int p = 0;
		for (int j = 20; j >= 0; j--) {
			if (p + (1 << j) < N && f[p + (1 << j)] >= k) {
				p += (1 << j);
			}
		}
		cout << p << '\n';
	}
}

