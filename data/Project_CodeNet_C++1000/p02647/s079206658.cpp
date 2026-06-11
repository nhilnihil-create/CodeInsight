#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(j, K)
    {
        vector<int> B(N, 0);
        rep(i, N)
        {
            int l = max(0, i - A[i]);
            int r = min(N - 1, i + A[i]);
            B[l]++;
            if (r + 1 < N)
                B[r + 1]--;
        }
        rep1(i, N)
        {
            B[i] += B[i - 1];
        }
        if (A == B)
            break;
        A = B;
    }
    rep(i, N)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
