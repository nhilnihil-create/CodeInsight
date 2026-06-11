#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const string YES = "Yes";
const string NO = "No";

void solve(long long A, long long B, long long C, long long D) {
    rep (i, 500) {
        if (i % 2 == 0) {
            C -= B;
        } else {
            A -= D;
        }

        if (C <= 0) {
            cout << YES << endl;
            return;
        } else if (A <= 0) {
            cout << NO << endl;
            return;
        }
    }
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
