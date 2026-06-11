#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long A, long long B) {
    if (A - B * 2 <= 0) {
        cout << 0 << endl;
    } else {
        cout << A - B * 2 << endl;
    }
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    solve(A, B);
    return 0;
}
