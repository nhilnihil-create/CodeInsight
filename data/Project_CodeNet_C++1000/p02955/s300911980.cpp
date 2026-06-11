#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep (i, n) cin >> a[i];
	ll sum = 0;
	rep (i, n) sum += a[i];
	int i;
	for (i = 1; i * i <= sum; i++) {
		if (sum % i != 0) continue;
		int x = sum / i;
		vector<int> b(n);
		ll subsum = 0, check = 0;
		rep (j, n) b[j] = a[j] % x;
		sort(all(b), [](int a, int b) {return a > b;});
		rep (j, n) subsum += b[j];
		rep (j, n) {
			if (subsum == 0) break;
			check += x - b[j];
			subsum -= x;
		}
		if (k >= check) {
			cout << x << "\n";
			return 0;
		}
	}
	for (; i >= 1; i--) {
		if (sum % i != 0) continue;
		int x = i;
		vector<int> b(n);
		ll subsum = 0, check = 0;
		rep (j, n) b[j] = a[j] % x;
		sort(all(b), [](int a, int b) {return a > b;});
		rep (j, n) subsum += b[j];
		rep (j, n) {
			if (subsum == 0) break;
			check += x - b[j];
			subsum -= x;
		}
		if (k >= check) {
			cout << x << "\n";
			return 0;
		}
	}
	return 0;
}