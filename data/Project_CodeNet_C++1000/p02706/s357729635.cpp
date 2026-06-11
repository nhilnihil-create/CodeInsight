#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    int n, m;
    cin >> n >> m;
    int day = 0;
    rep(i, m)
    {
        int a;
        cin >> a;
        day += a;
    }
    if (day <= n)
        cout << n - day << endl;

    else
        cout << -1 << endl;
}