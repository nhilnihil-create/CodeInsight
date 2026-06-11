#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    int AC = 0, WA = 0;
    rep(i, m)
    {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (cnt[p] == -1)
            continue;
        if (s == "AC")
        {
            AC++;
            WA += cnt[p];
            cnt[p] = -1;
        }
        else
            cnt[p]++;
    }
    cout << AC << " " << WA << endl;
}
