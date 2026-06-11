#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long X, D, K;
    cin >> X >> K >> D;
    X = abs(X);

    // if K is too small
    if (X / D >= K)
    {
        cout << abs(X - K * D) << endl;
        return 0;
    }

    // if ans is 0 or D
    if (X % D == 0)
    {
        if (abs(X / D - K) % 2 == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            cout << D << endl;
            return 0;
        }
    }

    // if K is large enough

    if (abs(K - X / D) % 2 == 0)
    {
        cout << abs(X - D * (X / D)) << endl;
        return 0;
    }
    if (abs(K - X / D) % 2 == 1)
    {
        cout << abs(X - D * (X / D + 1)) << endl;
        return 0;
    }
}