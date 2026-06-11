#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

#define int long long

const int inf = 2e9;
const int N = 2e5 + 15;
int n, a[N], b[N], ans;
priority_queue <pll> q;

#undef int

int main() {
	#define int long long
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		if(b[i] > a[i])
			q.push({b[i], i});
	}
	while(!q.empty()) {
		int i = q.top().se;
		q.pop();
		int prev = (i - 1 + n) % n;
		int next = (i + 1) % n;
		if(b[i] < b[prev] + b[next]) {
			puts("-1");
			return 0;
		}
		if(a[i] >= (b[prev] + b[next])) {
			if((b[i] - a[i]) % (b[prev] + b[next])) {
				puts("-1");
				return 0;
			}
			ans += (b[i] - a[i]) / (b[prev] + b[next]);
			b[i] = a[i];
			continue;
		}
		else {
			ans += b[i] / (b[prev] + b[next]);
			b[i] %= (b[prev] + b[next]);
			if(b[i] < a[i]) {
				puts("-1");
				return 0;
			}
			if(b[i] > a[i])
				q.push({b[i], i});
		}
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] != b[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}