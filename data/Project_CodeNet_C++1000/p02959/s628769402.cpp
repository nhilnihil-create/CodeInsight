#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A;
    vector<ll> B;
    for (ll i = 0; i < N + 1; ++i)
    {
        ll temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (ll i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        B.push_back(temp);
    }
    ll ans = 0;

    for (ll i = 0; i < N + 1; ++i)
    {
        ans += min(A[i], B[i]);
        B[i] = B[i] - min(A[i], B[i]);
        ans += min(A[i + 1], B[i]);
        A[i + 1] = A[i + 1] - min(A[i + 1], B[i]);
    }

    cout << ans << endl;
}
