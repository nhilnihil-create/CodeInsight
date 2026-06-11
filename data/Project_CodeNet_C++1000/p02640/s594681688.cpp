#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int mn = 2 * x, mx = 4 * x;
    if (y >= mn && y <= mx && y % 2 == 0) puts("Yes");
    else puts("No");
}
