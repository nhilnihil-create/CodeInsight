#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

long long p[200000][2];

int main()
{
    int N, D, i, j;
    cin >> N >> D;
    rep(i, N) cin >> p[i][0] >> p[i][1];

    int ans = 0;
    double d;

    rep(i, N)
    {
        d = sqrt(p[i][0] * p[i][0] + p[i][1] * p[i][1]);
        if (d <= D)
            ans++;
    }
    cout << ans << endl;
    return 0;
}