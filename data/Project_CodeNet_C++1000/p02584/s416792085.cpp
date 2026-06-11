#include <bits/stdc++.h>

using namespace std;

int main()
{
    long X, K, D;
    cin >> X >> K >> D;

    X = abs(X);
    long times = X / D;

    long ans;
    if (times >= K)
    {
        ans = X - K * D;
    }
    else
    {
        if ((K - times) % 2 == 0)
        {
            ans = X - times * D;
        }
        else
        {
            ans = abs(X - (times + 1) * D);
        }
    }

    cout << ans << endl;
}