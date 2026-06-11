// https://atcoder.jp/contests/abc138/tasks/abc138_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    double s = v[0];
    for (long i = 1; i < n; i++)
    {
        s = (s + v[i]) / 2.0;
    }
    cout << s << endl;
}
