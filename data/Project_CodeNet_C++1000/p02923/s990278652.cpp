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
	int n;
	cin >> n;
	vector<int> H(n), P(n);
	for (int i = 0; i < n; i++)cin >> H[i];
	for (int i = 1; i < n; i++) if (H[i - 1] >= H[i])P[i] = 1;
	for (int i = 0; i < n; i++)if (P[i])P[i] += P[i - 1];
	cout << *max_element(P.begin(), P.end()) << endl;

}