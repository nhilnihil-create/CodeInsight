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
    vector<int> x(n), y(n), per(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> y[i];

    rep(i, n) per[i] = i + 1;

    int s, t;
    int cnt = 0;
    do
    {
        cnt++;
        if (x == per)
            s = cnt;
        if (y == per)
        {
            t = cnt;
        }
    } while (next_permutation(all(per)));

    cout << abs(t - s) << endl;
    return (0);
}
