#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 200000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;

typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll N;

int main() {
	cin >> N;
	ll tmp = 1000000000000;
	for (ll i = 1; i*i <= N; i++)
	{
		if (N % i == 0) {
			tmp = min(tmp, N / i);
		}
	}
	cout << tmp + N / tmp - 2 << endl;
}