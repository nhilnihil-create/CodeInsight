#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(long long H, long long N, std::vector<long long> A) {
    rep(i, N) { H -= A[i]; }
    if (H <= 0) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    long long H;
    scanf("%lld", &H);
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(H, N, std::move(A));
    return 0;
}
