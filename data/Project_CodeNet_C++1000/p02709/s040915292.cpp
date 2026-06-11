#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <functional>
#include <random>
#include <time.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define MOD 1000000007
#define SORT(s) sort(s.begin(), s.end());
#define REVERSE(s) reverse(s.begin(), s.end());
#define SUM(s) accumulate(s.begin(), s.end(), 0LL);
#define P pair<int,int>
#define mp make_pair
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
//#define int ll
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ndx[8] = { 0,1,0,-1, 1,1,-1,-1 };
int ndy[8] = { 1,0,-1,0, 1,-1,-1,1 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }



int main() {
	int n;
	cin >> n;
	vector<P> a(n);
	rep(i, n) {
		int z; cin >> z;
		a[i] = mp(z, i);
	}
	SORT(a);
	REVERSE(a);

	vector<vector<ll>> dp(n + 1);
	rep(i, n+1) {
		dp[i].resize(n + 1);
	}
	dp[0][0] = 0;
	ll ans = 0;
	FOR(k, 1, n + 1) {
		auto t = a[k - 1];
		FOR(i, 0, k + 1) {
			int j = k - i;
			if (i == 0) {
				dp[i][j] = dp[i][j - 1] + (ll)t.first * abs(t.second - n + j);
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + (ll)t.first * abs(t.second - i + 1);
			}
			else {
				dp[i][j] = max(dp[i][j - 1] + (ll)t.first * abs(t.second - n + j),
					dp[i - 1][j] + (ll)t.first * abs(t.second - i + 1));
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}


