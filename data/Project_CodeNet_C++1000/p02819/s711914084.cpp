#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int x;
    cin >> x;

    vector<bool> era(100000, true);
    era[0] = era[1] = false;

    for (int i = 2; i < 100000; ++i)
        if (era[i])
            for (int j = i + i; j < 100000; j += i)
                era[j] = false;

    for (int i = x; i < 100000; ++i)
        if (era[i])
        {
            cout << i << endl;
            return 0;
        }
    cout << 100003 << endl;
}