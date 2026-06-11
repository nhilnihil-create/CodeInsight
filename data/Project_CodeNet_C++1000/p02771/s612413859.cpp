#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int a[3];
    rep(i, 3) cin >> a[i];
    sort(a, a + 3);
    if (a[0] == a[1] && a[1] != a[2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (a[0] != a[1] && a[1] == a[2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}