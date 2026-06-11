#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> A(M);
    rep(i, N) {
        int a, b; cin >> a >> b;
        if (a <= M)A[a - 1].push_back(b);
    }

    priority_queue<int> pq;
    int ans = 0;
    rep(i, M) {
        rep(j, A[i].size()) {
            pq.push(A[i][j]);
        }
        if (!pq.empty()) {
            ans += pq.top();
            //cout << ans << endl;
            pq.pop();
        }
    }
    cout << ans;



}