// https://atcoder.jp/contests/abc160/tasks/abc160_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long k, n;
    cin >> k >> n;

    long ma = -1;

    long start, frm, to;
    cin >> start;
    frm = start;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> to;
        ma = max(ma, to - frm);
        frm = to;
    }
    ma = max(ma, k - frm + start);
    cout << k - ma << endl;
    return 0;
}