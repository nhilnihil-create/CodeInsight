#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, K, S;
	cin >> N >> K >> S;

	vector<int> ans;
	for (int i = 0; i < K; ++i) ans.push_back(S);
	for (int i = K; i < N; ++i) ans.push_back(S == 1 ? 2 : S - 1);

	for (int i = 0; i < N; ++i) cout << ans[i] << " "; cout << endl;
	return 0;
}