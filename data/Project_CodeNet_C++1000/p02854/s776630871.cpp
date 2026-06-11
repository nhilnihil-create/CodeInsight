#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 10000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll N, A[200001];

int main() {
	cin >> N;
	ll S = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		S += A[i];
	}
	ll minx = S, sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += A[i];
		minx = min(minx, abs(sum - (S - sum)));
	}
	cout << minx << endl;
	return 0;
}