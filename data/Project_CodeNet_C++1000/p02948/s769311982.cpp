#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX_A = 1e5+1;
int N, M;

void solve() {
    cin >> N >> M;
    vector<P> jobs(N);
    for (int i = 0; i < N; ++i) {
        int a,  b;
        cin >> a >> b;
        jobs[i]  = P(a, b);
    }
    sort(jobs.begin(), jobs.end());
    ll ans = 0;
    priority_queue<int> q;
    int start = 0;
    for (int d = 1; d <= M; ++d) {
        for (int i = start; i < N; ++i) {
            P j = jobs[i];
            if (j.first <= d) {
                q.push(j.second);
                start++;
            } else {
                start = i;
                break;
            }
        }
        if (!q.empty()) {
            ans += q.top(); q.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

