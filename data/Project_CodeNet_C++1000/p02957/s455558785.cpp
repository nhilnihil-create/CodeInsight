#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull a, b;
    cin >> a >> b;  

    ull k = (a + b) / 2;
    if (k * 2 == a + b)
        cout << k;
    else
        cout << "IMPOSSIBLE";


    return 0;
}