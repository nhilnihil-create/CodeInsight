#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 3; ++i)
        if (i != a && i != b)
            cout << i << endl;
}