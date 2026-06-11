#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    int A[N];
    int B[N];
    int C[N - 1];

    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N-1) cin >> C[i];

    int ans = 0;
    rep(i, N)
    {
        ans += B[A[i] - 1];
        if (i == 0) continue;
        if (A[i] - A[i-1] == 1)
        {
            ans += C[A[i] - 2];
        }
    }

    cout << ans << endl;

    return 0;
}