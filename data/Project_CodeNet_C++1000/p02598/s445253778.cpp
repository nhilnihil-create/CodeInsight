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

bool judge(vll & vec, ll length, ll K) {
	ll cnt = 0;
	for (auto v : vec) {
		cnt += (v + length - 1) / length - 1;
	}
	
	return cnt <= K;
}

bool judge_2(vll& vec, ll length, ll K) {
	ll cnt = 0;
	for (auto v : vec) {
		if (v % length) {
			return false;
		}

		cnt += v / length - 1;
	}

	return cnt <= K;
}
ll quasi_max(ll lhs, ll rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	else {
		return rhs;
	}
}
int main() {
	ll n, k; cin >> n >> k;
	vll vec(n); rep(i, n) cin >> vec[i];

	ll min = 1;
	ll max = 1e10;
	ll mid;
	while (max - min > 1) {
		mid = (max + min) / 2;

		if (judge(vec,mid,k)) {
			max = mid;
		}
		else {
			min = mid;
		}
	}
	ll Mid = quasi_max(max - 1, 1);

	if (judge_2(vec, Mid, k)) {
		max = Mid;
	}
	cout << max << endl;
}