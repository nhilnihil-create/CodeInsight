#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int ans = 1;
    for (;; ans++)
    {
        if (ans * x % 360 == 0)
            break;
    }
    cout << ans << endl;
    return 0;
}