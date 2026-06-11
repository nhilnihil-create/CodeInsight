#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;

    for (ll i = -200; i <= 200; i++)
    {
        for (ll j = -200; j <= 200; j++)
        {
            if (i * i * i * i * i - j * j * j * j * j == N)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}
