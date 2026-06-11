#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b)for(int i=(a);i<=(b);i++)
#define repR(i,n) for(int i=n;i>=0;i--)
#define P pair<int, int>
#define sz(x) x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<int>
#define COUT(x) cout<<(x)<<endl
#define MA map<int,int>
#define SE set<int>
#define PQ priority_queue<int>
#define PQR priority_queue<int,VE,greater<int>>
#define COUT(x) cout<<(x)<<endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
const long long MOD = 1000000007;
const long long INF = 1LL << 50;
// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	VE xs(n), ys(n);
	rep(i, n)cin >> xs[i] >> ys[i];
	double ans = 0;
	rep(i, n) {
		int gx = xs[i]; int gy = ys[i];
		rep(k, 4) {
			int nx = -gy; int ny = gx;
			gx = nx; gy = ny;
			int sx = 0, sy = 0;
			int px = 0, py = 0;
			int qx = 0, qy = 0;
			auto dot = [&](int x1, int y1, int x2, int y2) {
				return x1 * x2 + y1 * y2;
			};
			auto cross = [&](int x1, int y1, int x2, int y2) {
				return x1 * y2 - x2 * y1;
			};
			rep(j, n) {
				int res = dot(xs[j], ys[j], gx, gy);
				if (res < 0)continue;
				if (res > 0) {
					sx += xs[j]; sy += ys[j];
					continue;
				}
				if (cross(xs[j], ys[j], gx, gy) > 0) {
					px += xs[j]; py += ys[j];
				}
				else {
					qx += xs[j]; qy += ys[j];
				}
			}
			rep(t, 4) {
				double bx = sx, by = sy;
				if (t & 1)bx += px, by += py;
				if (t & 2)bx += qx, by += qy;
				chmax(ans, bx*bx + by * by);
			}
		}
		
	}
	cout << fixed << setprecision(15) << sqrt(ans) << endl;
	return 0;
}