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
	int N, D;
	cin >> N >> D;
	Graph Z(N, vector<int>(D));
	rep(i, N) {
		rep(j, D) {
			cin >> Z.at(i).at(j);
		}
	}
	
	int ans = 0;
	for (int i = 0; i <	N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int norm = 0;
			for (int k = 0; k < D; k++)
			{
				int tmp = Z.at(i).at(k) - Z.at(j).at(k);
				norm += tmp * tmp;
			}

			bool flag = false;
			for (int m = 0; m*m<= norm; m++)
			{
				if (m*m==norm)
				{
					flag = true;
				}
			}
			if (flag)++ans;
		}
		
	}
	cout << ans << endl;
}