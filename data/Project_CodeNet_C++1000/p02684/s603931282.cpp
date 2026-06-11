#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long K, std::vector<long long> A) {
    rep(i, N) A[i]--;
    vector<int> pos(2 * N);
    vector<bool> visit(2 * N);
    pos[0] = 0;
    visit[0] = 1;

    int first = 0;
    int mod = 0;
    loop(i, 1, 2 * N) {
        auto next = A[pos[i - 1]];
        if (visit[next]) {
            first = find(pos.begin(), pos.end(), next) - pos.begin();
            mod = i - first;
            break;
        }
        visit[next] = 1;
        pos[i] = next;
    }
    if (K < first + mod) {
        cout << pos[K] + 1 << endl;
    } else {
        cout << pos[first + ((K - first) % mod)] + 1 << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
