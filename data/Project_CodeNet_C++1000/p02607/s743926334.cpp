#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x, cnt = 0; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if((i & 1) && (x & 1)) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}