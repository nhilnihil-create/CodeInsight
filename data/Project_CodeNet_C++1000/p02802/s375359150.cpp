#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, M;
bool S[MAX_N];
int WA[MAX_N];

int main() {
	
	cin >> N >> M;
	
	int WAnum = 0;
	int ACnum = 0;
	rep(i, N)S[i] = true;
	rep(i, M) {
		int t;
		string j;
		cin >> t >> j;
		t--;
		if (S[t])
		{
			if (j == "WA") {
				WA[t]++;
			}else 
			{ 
				S[t] = false;
				WAnum += WA[t];
				ACnum++;
			}
		}
	}
	cout << ACnum << " " << WAnum << endl;
}