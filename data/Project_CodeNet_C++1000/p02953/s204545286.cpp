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

int N;

int main() {
	cin >> N;
	vector<int> a(N);
	rep(i, N) {
		cin >> a.at(i);
	}
	rep(i, N) {
		if (i == 0 || a.at(i) > a.at(i - 1))a.at(i)--;
	}
	rep(i, N - 1) {
		if (a.at(i) > a.at(i + 1)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}