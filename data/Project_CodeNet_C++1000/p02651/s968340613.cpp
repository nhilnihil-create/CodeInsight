#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

void GaussJordan(vector<vector<int>> &mat) {
	int n = mat.size();
	int m = mat[0].size();
	int st = 0;
	rep(j, m) {
		int idx = -1;
		for (int i = st; i < n; i++) {
			if (mat[i][j]) {
				if (idx == -1) {
					idx = i;
					continue;
				}
				rep(k, m) {
					mat[i][k] ^= mat[idx][k];
				}
			}
		}
		for (int i = st - 1; i >= 0; i--) {
			if (mat[i][j]) {
				if (idx == -1) continue;
				rep(k, m) {
					mat[i][k] ^= mat[idx][k];
				}
			}
		}
		if (idx != -1) {
			rep(k, m) {
				swap(mat[idx][k], mat[st][k]);
			}
			st++;
		}
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		rep(i, n) cin >> a[i];
		string s;
		cin >> s;
		vector<vector<int>> mat(0, vector<int>(62));
		bool flag = false;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0') {
				vector<int> v(62);
				rep(j, 62) v[j] = (a[i] >> j) & 1;
				reverse(all(v));
				mat.pb(v); 
				GaussJordan(mat);
			}
			else {
				vector<ll> base(mat.size());
				rep(j, mat.size()) {
					vector<int> v = mat[j];
					reverse(all(v));
					rep(k, 62) {
						base[j] |= (ll)v[k] << k;
					}
				}
				rep(j, mat.size()) {
					rep(k, 62) {
						if (mat[j][k]) {
							if ((a[i] >> (61 - k)) & 1) a[i] ^= base[j];
							break;
						}
					}
				}
				if (a[i]) {
					cout << "1\n";
					flag = true;
					break;
				}
			}
		}
		if (!flag) cout << "0\n";
	}
}