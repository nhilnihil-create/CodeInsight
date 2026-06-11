#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define ll long long
#define ar array

int main()
{
    int n, a[1009];
    cin >> n;
    rep(i, n) cin >> a[i];
    bool flag = true;
    rep(i, n)
    {
        if (a[i] % 2 == 1)
            continue;
        if (a[i] % 3 != 0 && a[i] % 5 != 0)
            flag = false;
    }
    if (flag)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
    return 0;
}