// https://atcoder.jp/contests/abc132/tasks/abc132_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> d(n);
    for (long i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    cout << d[n / 2] - d[(n / 2) - 1] << endl;
}
