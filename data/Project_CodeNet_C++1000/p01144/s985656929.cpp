#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    while (1)
    {
        cin >> N >> M;
        if (N == 0)
            break;
        vector<P> v(N);
        rep(i, N) cin >> v[i].second >> v[i].first;
        sort(all(v)), reverse(all(v));
        int cost = 0, ans = 0;
        rep(i, N)
        {
            int D = v[i].second, P = v[i].first;
            if (cost + D <= M)
            {
                cost += D;
                continue;
            }
            int d = M - cost;
            D -= d;
            ans += D * P;
            cost = M;
        }
        cout << ans << endl;
    }
}
