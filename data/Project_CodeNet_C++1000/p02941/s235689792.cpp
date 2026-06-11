#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	int A[200001], B[200001];
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];

	int OK = 1;
	priority_queue<pair<int, int>> que;
	rep(i, N) {
		if (A[i] < B[i]) que.push(mp(B[i], i));
		if (A[i] > B[i]) OK = 0;
	}

	ll kotae = 0;
	while (que.size()) {
		auto p = que.top();
		que.pop();

		int k = 0;
		if (p.second == 0) k += B[N - 1];
		else k += B[p.second - 1];
		if (p.second == N - 1) k += B[0];
		else k += B[p.second + 1];

		if (p.first <= k) OK = 0;
		else {
			int k2 = p.first % k;
			if (k2 < A[p.second]) {
				if ((A[p.second] - k2) % k) OK = 0;
				else {
					k2 = A[p.second];
				}
			}
			kotae += (p.first - k2) / k;
			B[p.second] = k2;
			if (B[p.second] > A[p.second]) que.push(mp(B[p.second], p.second));
			if (B[p.second] < A[p.second]) OK = 0;
		}
	}

	if (OK) co(kotae);
	else co(-1);

	Would you please return 0;
}