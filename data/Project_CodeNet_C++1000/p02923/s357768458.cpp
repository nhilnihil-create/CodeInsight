// https://atcoder.jp/contests/abc139/tasks/abc139_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int cont = 0;
    long prev;
    cin >> prev;
    for (int i = 1; i < n; i++)
    {
        long h;
        cin >> h;
        if (h <= prev)
        {
            cont++;
        }
        else
        {
            ans = max(ans, cont);
            cont = 0;
        }
        prev = h;
    }
    ans = max(ans, cont);
    cout << ans << endl;
    return 0;
}
