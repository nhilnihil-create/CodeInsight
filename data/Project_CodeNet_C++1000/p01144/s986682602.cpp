#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	for (;;) {
		int N, M; cin >> N >> M;
		if (N == 0 && M == 0) break;
		vector<i_i> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int D = v[i].second, P = v[i].first;
			int x = min(D, M);
			M -= x;
			ans += (D - x) * P;
		}
		cout << ans << endl;
	}
}