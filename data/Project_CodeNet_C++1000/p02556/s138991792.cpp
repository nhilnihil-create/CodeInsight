#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e9;

int main()
{
    int N;
    cin >> N;
    ll xdist_min = INF, xdist_max = -INF, ydist_min = INF, ydist_max = -INF;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        xdist_min = min(xdist_min, x + y);
        xdist_max = max(xdist_max, x + y);
        ydist_min = min(ydist_min, x - y);
        ydist_max = max(ydist_max, x - y);
    }

    cout << max(xdist_max - xdist_min, ydist_max - ydist_min) << endl;
}