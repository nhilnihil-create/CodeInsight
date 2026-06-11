// https://atcoder.jp/contests/abc152/tasks/abc152_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mi = n + 1;
    int ans = 0;
    for (long i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p <= mi)
        {
            ans++;
            mi = p;
        }
    }

    cout << ans << endl;
    return 0;
}
