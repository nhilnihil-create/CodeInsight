#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_E = 100000000;
const int MAX_V = 100000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	int X;
	cin >> X;
	for (int i = 0; i <= X/100 ; i++)
	{
		int zan = X - i * 100;
		if (0<= zan && zan<= 5*i)
		{
			puts("1");
			return 0;
		}
	}
	puts("0");
	return 0;
}
