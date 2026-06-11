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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int calc(int a, int L) {
	stringstream ss; ss << a;
	string s = ss.str();
	while (s.length() < L) s = '0' + s;
	sort(s.begin(), s.end());
	stringstream ss1(s);
	int mini; ss1 >> mini;
	reverse(s.begin(), s.end());
	stringstream ss2(s);
	int maxi; ss2 >> maxi;
	return maxi - mini;
}

int main() {
	for (;;) {
		int a, L; cin >> a >> L;
		if (a == 0 && L == 0) break;
		map<int, int> m;
		m[a] = 0;
		for (int i = 1; ; i++) {
			a = calc(a, L);
			if (m.count(a)) {
				cout << m[a] << ' ' << a << ' ' << i - m[a] << endl;
				break;
			}
			m[a] = i;
		}
	}
}