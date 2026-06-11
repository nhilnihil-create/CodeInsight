// https://atcoder.jp/contests/abc134/tasks/abc134_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> a(n);
    for (long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long> b(n);
    for (long i = 0; i < n; i++)
    {
        b[i] = a[i]; // copy
    }
    sort(b.begin(), b.end(), greater<long>());
    long first = b[0];
    long second = b[1];

    for (long i = 0; i < n; i++)
    {
        if (a[i] == first)
        {
            cout << second << endl;
        }
        else
        {
            cout << first << endl;
        }
    }

    return 0;
}
