#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = 0;
    rep2(i, 1, n - 1)
    {

        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) || (p[i - 1] > p[i] && p[i] > p[i + 1]))
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
