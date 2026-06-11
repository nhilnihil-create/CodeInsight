// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a(101, -1);
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }

    vector<int> called_row(3, 0);
    vector<int> called_col(3, 0);
    int d = 0;
    int u = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        // cout << b << endl;
        if (a[b] == -1)
            continue;
        int r = a[b] / 3;
        int c = a[b] % 3;
        called_row[r]++;
        called_col[c]++;
        if (r == c)
            d++;
        if (r + c == 2)
            u++;
        // cout << called_row[0] << called_row[1] << called_row[2] << endl;
    }

    bool cond = false;
    cond |= (d == 3);
    cond |= (u == 3);
    for (int i = 0; i < 3; i++)
    {
        cond |= (called_row[i] == 3);
        cond |= (called_col[i] == 3);
    }
    cout << (cond ? "Yes" : "No") << endl;
    return 0;
}
