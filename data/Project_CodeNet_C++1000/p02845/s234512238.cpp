#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

constexpr int mod = 1000000007;

int main()
{
    int n;
    cin >> n;

    vector<int> color(3, 0);
    ll ans = 1;
    rep(i, n)
    {
        int a;
        cin >> a;
        int val = 0;
        bool add = true;
        rep(j, 3)
        {
            if (color[j] == a)
            {
                if (add)
                {
                    add = false;
                    ++color[j];
                }
                ++val;
            }
        }
        ans *= val;
        ans %= mod;
    }

    cout << ans << endl;
}