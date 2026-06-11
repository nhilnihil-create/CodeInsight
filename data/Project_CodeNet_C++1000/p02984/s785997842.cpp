#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    ll S = 0;
    rep(i, n) cin >> A[i];
    rep(i, n) S += A[i];
    ll S2 = 0;
    for (int i = 1; i <= n - 2; i += 2)
        S2 += A[i];
    B[0] = S - 2 * S2;
    cout << B[0] << " ";
    for (int i = 1; i < n; i++)
    {
        B[i] = 2 * A[i - 1] - B[i - 1];
        cout << B[i] << " ";
    }
    cout << endl;
}