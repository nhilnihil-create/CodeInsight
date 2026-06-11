#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }




int main() {
	int A, B;
	cin >> A >> B;
	for (int i = 10; i <= 1009; i++)
	{
		int c = i * 0.08;
		int d = i * 0.1;
		if (c==A && d==B)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}