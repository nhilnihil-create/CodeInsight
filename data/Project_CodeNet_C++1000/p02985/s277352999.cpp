#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;

ll n , k , mod=1e9+7 , fac[N] , inv[N] , ans=1;

vector<int> adj[N];

ll fp(ll b , ll p)
{
    if (!p) return 1;
    ll ans = fp(b , p/2);
    ans = (ans*ans)%mod;
    if (p%2) ans = (ans*b)%mod;
    return ans;
}

void pre()
{
    fac[0]=1 , inv[0]=1;
    for(ll i=1; i<N; i++)
    {
        fac[i] = (i*fac[i-1])%mod;
        inv[i] = fp(fac[i] , mod-2);
    }
}

ll nCr(ll nn , ll r)
{
    if (r > nn) return 0;
    return (((fac[nn] * inv[r])%mod)*inv[nn-r])%mod;
}

void imp()
{
    cout << "0\n";
    exit(0);
}

void dfs(int node , int p)
{
    if (node == 1) ans = (ans*k)%mod;

    ll cnt=0 , rem = k-1;
    for(auto ch : adj[node])
    {
        if (ch != p) cnt++;
    }
    if (cnt == 1)
    {
        if (node != p) rem--;
       // cout << rem << ' ' << cnt << " how\n";
        if (rem <= 0) imp();
        ans = (ans*rem)%mod;
    }
    else if (cnt > 1)
    {
        if (node != p) rem--;
        if (cnt > rem) imp();
        ll tmp = (nCr(rem , cnt)*fac[cnt])%mod;
        ans = (ans*tmp)%mod;
    }

    for(auto ch : adj[node])
    {
        if (ch != p)
        {
            dfs(ch , node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i=1; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y) , adj[y].push_back(x);
    }

    pre();
    dfs(1,1);

    cout << ans << '\n';

    return 0;
}