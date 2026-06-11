// https://atcoder.jp/contests/abc150/tasks/abc150_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n), p(n), q(n);
    for (int i = 0; i < n; i++)
        s[i] = i + 1; // [1,2,3,...,N]
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    long pi, qi;
    long i = 0;
    do
    {
        if (s == p)
        {
            pi = i;
        }
        if (s == q)
        {
            qi = i;
        }
        i++;
    } while (next_permutation(s.begin(), s.end()));
    cout << abs(pi - qi) << endl;

    return 0;
}
