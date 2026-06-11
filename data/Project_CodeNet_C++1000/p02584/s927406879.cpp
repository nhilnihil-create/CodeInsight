#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, K, D;

int main()
{
    cin >> X >> K >> D;
    if (X < 0) X = -X;
    if (D <= X / K) X -= K * D;
    else {
        ll tims = X / D;
        X -= tims * D;
        K -= tims;
        if (K % 2) X = abs(X - D);
    }
    cout << X << endl;
    return 0;
}
