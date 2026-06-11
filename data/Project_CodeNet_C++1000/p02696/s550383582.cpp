#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long A, long long B, long long N) {
    auto x = min(B-1, N);
    cout << floor((double)A*x/B) - A*floor((double)x/B) << endl;
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long N;
    scanf("%lld", &N);
    solve(A, B, N);
    return 0;
}
