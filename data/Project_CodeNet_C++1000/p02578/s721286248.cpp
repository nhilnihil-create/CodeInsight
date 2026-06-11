#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 200000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) {
		cin >> A.at(i);
	}
	ll ans = 0;
	int MAXnum = 0;
	rep(i, N) {
		MAXnum = max(MAXnum, A[i]);
		int tmp = MAXnum;
		ans += tmp - A[i];
	}
	cout << ans << endl;
}