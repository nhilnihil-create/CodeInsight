#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sd second
#define ft first

#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int32_t main()
{
    ios;
    int x;
    cin >> x;
    for (int i = -130; i < 130; i++)
    {
        for (int j = -130; j < 130; j++)
        {
            if ((i * i * i * i * i - j * j * j * j * j) == x)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}