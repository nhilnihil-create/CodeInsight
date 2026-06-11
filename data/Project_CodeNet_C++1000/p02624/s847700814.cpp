#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

long long N;
long long ans = 0;

int main()
{
    int i, j;
    cin >> N;

    rep(1, i, 1 + N)
    {
        ans += (2 * i + ((N / i) - 1) * i) * (N / i) / 2;
    }

    cout << ans << endl;
    return 0;
}