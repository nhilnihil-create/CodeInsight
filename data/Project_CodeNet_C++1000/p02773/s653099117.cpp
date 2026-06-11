#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_V = 100000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
map<string, int> score;

int main() {
	cin >> N;
	rep(i, N) {
		string tmp;
		cin >> tmp;
		score[tmp] += 1;
	}

	int cnt = 0;
	for(auto it : score) {
		cnt = max(cnt, it.second);
	}

	for (auto it : score) {
		if (it.second== cnt)
		{
			cout << it.first << endl;
		}
	}
}