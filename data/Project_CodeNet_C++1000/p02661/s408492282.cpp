#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (n % 2 == 1)
    {
        ll l = A[n / 2];
        ll r = B[n / 2];
        cout << r - l + 1 << endl;
    }
    else
    {
        long double l = (A[n / 2 - 1] + A[n / 2]) / 2.0;
        long double r = (B[n / 2 - 1] + B[n / 2]) / 2.0;
        cout << (ll)((r - l) / 0.5) + 1 << endl;
    }
}