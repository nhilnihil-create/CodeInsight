#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int len = a.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            ans++;
    }
    cout << ans;
    return 0;
}