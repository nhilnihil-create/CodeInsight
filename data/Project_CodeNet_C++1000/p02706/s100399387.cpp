#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int r;
        cin >> r;
        n -= r;
    }
    if (n < 0)
        cout << -1;
    else
        cout << n;
}