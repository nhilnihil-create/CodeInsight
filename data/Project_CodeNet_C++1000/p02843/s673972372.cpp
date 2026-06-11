#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int x;
    cin >> x;

    int n = x / 100;
    if (5 * n >= x % 100)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}