#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

int main() {
    int N, M; cin >> N >> M;
    ll ans = 0;
    priority_queue<int> p;
    vector<vector<int>> jobs(M+1); 
    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        if (A <= M) jobs[A].push_back(B);
    }
    for (int i = 1; i <= M; i++) {
        for (int x : jobs[i]) {
            p.push(x);
        }
        if (!p.empty()) {
            ans += p.top();
            p.pop();
        }
    }
    cout << ans << endl;
}