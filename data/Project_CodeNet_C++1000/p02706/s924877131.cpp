#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int day = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        day += a[i];
    }
    if (n >= day)
    {
        cout << n - day << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}