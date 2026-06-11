#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    int curr = 100;
    int ans = 0;
    while (curr < n)
    {
        curr += curr / 100;
        ans++;
    }
    cout << ans;
}