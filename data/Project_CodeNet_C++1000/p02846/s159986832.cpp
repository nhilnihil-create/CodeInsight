#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    if (A1 < B1)
    {
        swap(A1, B1);
        swap(A2, B2);
    }

    if (A2 > B2)
    {
        cout << 0 << endl;
        return 0;
    }

    int64_t d1 = T1 * A1 - T1 * B1;
    int64_t d2 = T1 * (B1 - A1) + T2 * (B2 - A2);
    if (d2 < 0)
    {
        cout << 0 << endl;
    }
    else if (d2 == 0)
    {
        cout << "infinity" << endl;
    }
    else
    {
        if (d1 % d2 == 0)
        {
            cout << d1 / d2 * 2 << endl;
        }
        else
        {
            cout << d1 / d2 * 2 + 1 << endl;
        }
    }
}