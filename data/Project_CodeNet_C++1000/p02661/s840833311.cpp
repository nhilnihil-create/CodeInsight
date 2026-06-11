#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (N%2) {
        cout << B[N/2] - A[N/2] + 1 << endl;
    }
    else {
        double M = (B[N/2] + B[N/2-1]) / 2.0;
        double m = (A[N/2] + A[N/2-1]) / 2.0;
        cout << (ll)((M - m + 0.5) * 2) << endl;
    }
}
