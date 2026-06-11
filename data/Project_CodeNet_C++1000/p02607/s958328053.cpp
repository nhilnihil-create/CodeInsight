#include <bits/stdc++.h>

using namespace std;

void fast();

/*
*
* Watch out! Another Buggy Code From Muhammad_Mamdouh, Happy Coding;
*
*/

int main()
{
    fast();
    int n, square = 0; cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;

        if (i % 2 != 0 && x % 2 != 0)
            ++square;
    }

    cout << square;

    return 0;
}

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}