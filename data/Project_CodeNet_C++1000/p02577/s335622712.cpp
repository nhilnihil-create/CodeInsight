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

string N;

int main() {
	cin >> N;
	ll tmp = 0;
	rep(i, N.size()) {
		tmp += N.at(i) - '0';
	}
	if (tmp%9==0)
	{
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}