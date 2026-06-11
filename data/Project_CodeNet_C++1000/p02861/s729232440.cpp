#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n) p[i] = i;
    double sum = 0.0;
    int cnt = 0;
    do
    {
        rep(i, n - 1)
        {
            int xx = x[p[i]] - x[p[i + 1]];
            int yy = y[p[i]] - y[p[i + 1]];
            sum += sqrt(xx * xx + yy * yy);
        }
        cnt++;
    } while (next_permutation(p.begin(), p.end()));
    printf("%.10f\n", sum / cnt);
    return 0;
}