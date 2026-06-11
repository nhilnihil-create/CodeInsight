#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int C(int n) {
	return n * (n - 1) / 2;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> ans;
	if (K > C(N - 1)) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			ans.push_back({ i + 1,j + 1 });
		}
	}
	for (int i = 0; i < N - 1; i++) {
		ans.push_back({ i + 1 ,N });
	}
	cout << ans.size() - K << endl;
	for (int i = K; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
