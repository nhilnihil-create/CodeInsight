#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	int N;
	cin >> N;
	vector<int> B(N - 1);
	rep(i, N - 1) {
		cin >> B.at(i);
	}

	int ans = B.at(0);
	
	for (int i = 0; i < N-2; i++)
	{
		if (B.at(i)<B.at(i+1))
		{
			ans += B.at(i);
		}
		else {
			ans += B.at(i + 1);
		}
	}
	ans += B.at(N -2);
	cout << ans << endl;
}