// https://atcoder.jp/contests/abc142/tasks/abc142_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> a(n);
    for (long i = 1; i <= n; i++)
    {
        long x;
        cin >> x;
        a[--x] = i;
    }
    for (long i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
