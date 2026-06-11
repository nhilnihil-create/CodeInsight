#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)
typedef long long ll;

int main()
{
    int x;
    cin >> x;

    int a, b;
    for (a = -120; a <= 120; a++)
        for (b = -120; b <= 120; b++)
            if (a * a * a * a * a - b * b * b * b * b == x)
            {
                cout << a << " " << b << endl;
                return 0;
            }
}