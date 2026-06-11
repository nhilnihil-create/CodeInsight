// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;

    long l, r;
    l = (100 * n + 107) / 108;
    r = (100 * (n + 1) + 107) / 108;
    if (l < r)
    {
        cout << l << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    return 0;
}
