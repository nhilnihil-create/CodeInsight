#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<int> bit(n);
    rep(i, n) bit[i] = i;

    double ans = 0;
    int cnt = 0;
    do
    {
        rep(i, n - 1)
        {
            ans += sqrt(pow(x[bit[i + 1]] - x[bit[i]], 2.0) + pow(y[bit[i + 1]] - y[bit[i]], 2.0));
        }
        cnt++;
    } while (next_permutation(all(bit)));

    printf("%6lf\n", ans / cnt);

    return (0);
}
