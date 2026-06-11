// https://atcoder.jp/contests/abc140/tasks/abc140_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int p;
    cin >> p;
    long ans = p;
    for (int i = 0; i < n - 2; i++)
    {
        int b;
        cin >> b;
        ans += min(b, p);
        p = b;
    }
    ans += p;
    cout << ans << endl;
    return 0;
}
