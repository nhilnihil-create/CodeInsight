#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    priority_queue<P> Q;
    for (int i = 0; i < N; i++) {
        if (A[i] < B[i]) {
            Q.emplace(B[i], i);
        }
    }
    ll ans = 0;
    while (!Q.empty()) {
        P p = Q.top(); Q.pop();
        int cur = p.second;
        int prv = (cur + N - 1) % N;
        int nxt = (cur + 1) % N;
        int sum = B[prv] + B[nxt];
        if (B[cur] <= sum) {
            cout << -1 << endl;
            return 0;
        }
        if ((B[cur] - A[cur]) % sum == 0) {
            ans += (B[cur] - A[cur]) / sum;
            B[cur] = A[cur];
            continue;
        }
        ans += B[cur] / sum;
        B[cur] %= sum;
        if (A[cur] < B[cur]) {
            Q.emplace(B[cur], cur);
        }
    }
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
 }