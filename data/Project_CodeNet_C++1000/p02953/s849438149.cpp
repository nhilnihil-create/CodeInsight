#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    int hmax = (h[0] == 1) ? h[0] : h[0] - 1;
    rem(i, 1, n)
    {
        if (h[i] > hmax)
            hmax = h[i] - 1;
        else if (h[i] < hmax)
        {
            cout << "No"
                 << "\n";
            return 0;
        }
    }

    cout << "Yes"
         << "\n";

    return 0;
}