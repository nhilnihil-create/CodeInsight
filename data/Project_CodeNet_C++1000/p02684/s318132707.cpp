#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pdd;

#define INF 0x7f7f7f
#define mem(a,b) memset(a , b , sizeof(a))
#define FOR(i, x, n) for(int i = x;i <= n; i++)
// const ll mod = 1e9 + 7;
// const int maxn = 1e5 + 10;
// const double eps = 1e-6;

ll town[200005];
int vis[200005];
ll rul1[200005];
ll rul2[200005];

ll n, k;

void solve()
{
    ll cnt1 = 1;
    ll cnt2 = 1;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> town[i];
    }
    ll ans = 1;
    ll m = k;
    while(m--) // 判断循环一次需要传送多少
    {
        ans = town[ans]; // 传送
        if(vis[ans] > 2)
            break;
        if(vis[ans] == 0)
            rul1[cnt1++] = ans;
        else if(vis[ans] == 1)
            rul2[cnt2++] = ans;
        vis[ans]++;
    }
    cnt1--;
    cnt2--;
    if(k <= cnt1)
        cout<<rul1[k] << endl;
    else if(cnt2 == -1 && k > cnt1)
    {
        ll a = k % cnt1;
        if(!a) a = cnt1;
    }
    else if(cnt2 != -1 && k > cnt1)
    {
        k -= cnt1;
        ll a = k % cnt2;
        if(!a)
            a = cnt2;
        cout << rul2[a] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
#ifdef FZT_ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
#endif
    return 0;
}
