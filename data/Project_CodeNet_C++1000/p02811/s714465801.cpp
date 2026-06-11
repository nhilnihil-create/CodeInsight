#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int k, x;
    cin >> k >> x;

    if (500 * k >= x)
        puts("Yes");
    else
        puts("No");
}