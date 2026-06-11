#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long A, long long B, long long C, long long D) {
    ll CDlcm = (C * D) / __gcd(C, D);
    A--;
    ll tmpA = A - A / C - A / D + A / CDlcm;
    ll tmpB = B - B / C - B / D + B / CDlcm;
    cout << tmpB - tmpA << endl;
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    long long D;
    scanf("%lld", &D);
    solve(A, B, C, D);
    return 0;
}
