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
	int N;
	cin >> N;
	vector<int> vec(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> vec.at(i);
	}
	int j = 1;
	int cnt = 0;
	for (int i = 1; i <= N ; i++)
	{
		if (vec.at(i)==j)
		{
			cnt++;
			j++;
			
		}
	}
	if (cnt == 0)cout << -1 << endl;
	else cout << N - cnt << endl;
}
