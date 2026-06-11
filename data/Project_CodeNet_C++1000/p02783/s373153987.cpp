#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long H, long long A) {
    if (H % A == 0) {
        cout << H / A << endl;
    } else {
        cout << H / A + 1 << endl;
    }
}

int main() {
    long long H;
    scanf("%lld", &H);
    long long A;
    scanf("%lld", &A);
    solve(H, A);
    return 0;
}
