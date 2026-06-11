#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000000 + 7
#define PI 3.14159265359

const long long INF = 100000;
typedef pair<int,int> P;
typedef long long ll;

using Graph = vector<vector<int>>;

typedef pair<int,int> P;

vector<int> A;
vector<int> B;
vector<ll> ans;

int N, M, Q;
vector<int> a, b, c, d;

ll score(vector<int> &A, int Q, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
	ll res = 0;
	for (int i = 0; i < Q; i++) {
		if (A[b[i] - 1] - A[a[i] - 1] == c[i]) res += d[i]; 
	}

	return res;
}

//Aにnextを追加し、next以上M以下の数をさらに追加していく
void dfs(vector<int> &A, int next, int N, int M, int Q, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d) {
	A.push_back(next);

	if (A.size() == N) {
		//for (int i = 0; i < N; i++) cout << A[i] << " ";
		//cout << endl;
		ans.push_back(score(A, Q, a, b, c, d));
		return;
	}

	for (int i = next; i <= M; i++) {
		dfs(A, i, N, M, Q, a, b, c, d);
		A.pop_back();
	}
	

}

int main() {
	cin >> N >> M >> Q;
	a.resize(Q);
	b.resize(Q);
	c.resize(Q);
	d.resize(Q);

	for (int i = 0; i < Q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	for (int i = 1; i <= M; i++) {
		dfs(A, i, N, M, Q, a, b, c, d);
		A = B;
	}
	sort(ans.begin(), ans.end());

	cout << ans[ans.size()-1] << endl;
}
