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
	vector<bool> a(300000, true);
	a[0] = a[1] = false;
	for (int i = 2; i < 300000; i++)
		if (a[i])
			for (int j = i * 2; j < 300000; j += i)
				a[j] = false;
	vector<int> sum(300001);
	for (int i = 1; i < 300000; i++)
		sum[i] = sum[i - 1] + a[i];
	for (;;) {
		int n; cin >> n;
		if (n == 0) break;
		cout << sum[n * 2] - sum[n] << endl;
	}
}