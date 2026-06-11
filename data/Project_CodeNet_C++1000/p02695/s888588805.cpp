#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;
#define pb push_back
#define mp make_pair
#define all(c) ((c).begin(), (c).end)
#define sz(a) int((a).size())
#define tr(c,i) for(typeof(c).begin() i = (c).begin();it!=(c).end();it++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end)
#define cp(s,c) copy(all(c),(s).begin())
// note that data is copied from C --> S's reference

void dfs(int n, int m, int pre_num, vi now, vvi &num)
{
    if (now.size() == n)
    {
        num.pb(now);
        return;
    }
    for (int i = pre_num; i <= m; i++)
    {
        auto tmp_now = now;
        tmp_now.pb(i);
        dfs(n, m, i, tmp_now, num);
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vi a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;
    vvi num;
    vi now;
    dfs(n, m, 1, now, num); // on which iteration are we .
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < q; j++)
        {
            if (num[i][b[j]] - num[i][a[j]] == c[j])
                sum += d[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}