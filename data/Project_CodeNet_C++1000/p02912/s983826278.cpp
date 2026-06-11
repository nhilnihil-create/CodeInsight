#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M; 
	std::priority_queue<int> que;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		que.push(num);
	}
	for (int n = 0;n<M;++n) {
		int num = que.top();
		que.pop();
		que.push(num/2);
	}
	long long ans = 0;
	for (int n = 0; n < N; ++n) {
		ans += que.top(); 
		que.pop();
	}
	cout << ans << endl;
	return 0;
}
