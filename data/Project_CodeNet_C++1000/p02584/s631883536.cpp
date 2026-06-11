#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    ll t = X / D;
    ll p = K - t;
    if (K >= t)
        if (p % 2 == 0)
            cout << X - t * D;
        else
            cout << (t + 1) * D - X;
    else
        cout << X - K * D;
    return 0;
}