// https://atcoder.jp/contests/abc127/tasks/abc127_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long k;
    int q;
    cin >> n >> k >> q;
    vector<int> s(n, k - q);

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        s[--a]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
