#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int X, K, D;
    cin >> X >> K >> D;

    long int ans = 0;
    long int k = abs(X) / abs(D);

    if (k >= K)
        ans = abs(X) - abs(D * K);
    else
    {
        if ((K - k) % 2 == 0)
            ans = abs(X) - abs(D * k);
        else
            ans = - (abs(X) - abs(D * (k + 1)));
    }
    cout << ans << endl;
}