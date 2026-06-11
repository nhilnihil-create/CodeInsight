
// E - Rotation Matching

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> ans;

	int i=1;
	for (int j=M; j>=1; j-=2) {
		ans.push_back(make_pair(i, i+j));
		i++;
	}

	i = 1+M+1;
	for (int j=M-1; j>=1; j-=2) {
		ans.push_back(make_pair(i, i+j));
		i++;
	}

	for (auto a : ans) {
		cout << a.first << " " << a.second << endl;
	}

	return 0;
}