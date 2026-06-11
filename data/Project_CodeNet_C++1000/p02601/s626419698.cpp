#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(long long A, long long B, long long C, long long K) {
    rep(i, K) {
        if (B <= A) {
            B *= 2;
        } else if (C <= B) {
            C *= 2;
        }
    }
    if (A < B && B < C) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    long long K;
    scanf("%lld", &K);
    solve(A, B, C, K);
    return 0;
}
