#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) {
		int tmp;
		cin >> tmp;
		tmp--;
		A.at(tmp) = i + 1;
	}
	rep(i, N) {
		cout << A.at(i) << " ";
	}
	return 0;
}