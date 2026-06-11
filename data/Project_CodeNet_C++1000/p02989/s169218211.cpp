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
	vector<int> d(N);
	rep(i, N) {
		cin >> d.at(i);
	}
	sort(d.begin(), d.end());
	int num = d.size() / 2;
	int ans = d.at(num) - d.at(num - 1);
	cout << ans << endl;

}