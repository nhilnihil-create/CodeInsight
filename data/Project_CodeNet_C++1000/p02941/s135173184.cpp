#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

long long solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    using P = pair<int, int>;
    priority_queue<P> pq;
    long long ans = 0;
    rep(i, 0, N) if(A[i] != B[i]) pq.push(P(B[i], i));
    while(!pq.empty()) {
        P t = pq.top(); pq.pop();
        int i = t.second;
        int v = B[(i + N - 1) % N] + B[(i + 1) % N];
        if((B[i] - A[i]) % v == 0) {
            ans += (B[i] - A[i]) / v;
            B[i] = A[i];
        } else if(B[i] <= v) return -1;
        else {
            ans += (B[i] / v);
            B[i] %= v;
        }
        if(A[i] < B[i]) pq.push(P(B[i], i));
        else if(A[i] > B[i]) return -1;
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
