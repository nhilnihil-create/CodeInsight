#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << setprecision(16) << 1.0000000000 << endl;
    }
    else if (n % 2 == 0)
    {
        cout << setprecision(16) << 0.5000000000 << endl;
    }
    else
    {
        double ans = (((double)n + 1.0) / 2) / n;
        cout << setprecision(16) << ans << endl;
    }
}