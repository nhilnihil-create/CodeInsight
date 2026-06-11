#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;
#define int ll

ll mpow(ll x, ll n) { //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		n = n >> 1;
	}
	return ans;
}

signed main() {
	int N, A, B; cin >> N;
	int maxL = 60;
	vector<vector<int>> accum(maxL, vi(2)); // {N of zero, N of one}
	vector<bitset<60>> input(N); 
	rep(i, N) {
		int x; cin >> x;
		bitset<60> bs = x;
		input[i] = bs;
	}
	;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < maxL; j++) {
			if (input[i][j] == 0) {
				accum[j][0]++;
			}
			else {
				accum[j][1]++;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < maxL; j++) {
			if (input[i][j] == 0) {
				res += mpow(2, j) * accum[j][1] % MOD;
				res %= MOD;
			}
			else {
				res += mpow(2, j) * accum[j][0] % MOD;
				res %= MOD;
			}
		}
	}
	res %= MOD;
	if (res % 2 != 0) {
		res += MOD;
		res /= 2;
		res %= MOD;
	}
	else {
		res /= 2;
	}
	cout << res << endl;
}