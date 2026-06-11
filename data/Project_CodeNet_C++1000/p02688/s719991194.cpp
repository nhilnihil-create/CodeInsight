#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cmath>
#include <limits>
typedef long long ll;
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mod 1000000007
#define fst first
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//ユークリッドの互除法
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }


int main()
{	
	int n, k;
	cin >> n >> k;
	vector<int> d(n);
	rep(i, k) {
		int m;
		cin >> m;
		rep(j, m) {
			int a;
			cin >> a;
			d[a - 1] = 1;
		}
	}
	int ans = 0;
	rep(i, n) {
		if (d[i] == 0) {
			ans++;
		}
	}
	cout << ans << endl;
}
