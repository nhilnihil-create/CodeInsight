// https://atcoder.jp/contests/abc153/tasks/abc153_d

#include <bits/stdc++.h>
using namespace std;

long rec(long h)
{
    if (h == 1)
    {
        return 1;
    }
    else
    {
        return rec(h / 2) * 2 + 1;
    }
}

int main()
{
    long h;
    cin >> h;
    cout << rec(h) << endl;
    return 0;
}
