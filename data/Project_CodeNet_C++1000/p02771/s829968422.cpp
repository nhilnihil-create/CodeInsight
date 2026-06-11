#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int same = 0;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
        ++same;

    if (a == c)
        ++same;

    if (c == b)
        ++same;

    if (same == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}