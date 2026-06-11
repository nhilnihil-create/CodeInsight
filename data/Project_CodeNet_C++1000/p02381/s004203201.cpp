#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
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
 
int MOD = 1000000007;

int main() {
	for (;;) {
		int n; cin >> n;
		if (n == 0) break;
		vector<int> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];
		int sum = 0;
		for (int i = 0; i < n; i++) sum += s[i];
		double m = (double)sum / n;
		double _sum = 0;
		for (int i = 0; i < n; i++) _sum += (s[i] - m) * (s[i] - m);
		printf("%.10f\n", sqrt(_sum / n));
	}
}