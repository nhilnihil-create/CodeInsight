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
	int n; cin >> n;
	vector<double> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	for (int p = 1; p <= 3; p++) {
		double sum = 0;
		for (int i = 0; i < n; i++) sum += pow(abs(x[i] - y[i]), p);
		printf("%.10f\n", pow(sum, 1.0 / p));
	}
	double maxi = 0;
	for (int i = 0; i < n; i++) maxi = max(maxi, abs(x[i] - y[i]));
	printf("%.10f\n", maxi);
}