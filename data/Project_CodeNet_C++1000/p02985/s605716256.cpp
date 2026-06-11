#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

const ll MOD = 1e9 + 7LL;
const int MAXN = 1e5+1;
int n, k;

vi adj[MAXN];

ll resenje = 0LL;

void dfs(int s, int prosli, bool manje)
{
    if(manje)
        return;

    int brojac = 2;

    for(auto e : adj[s])
    {
        if(e == prosli)
            continue;

        ll zaMnoziti = (ll)k-(ll)brojac;
        ++brojac;

        if(s == 1)
            ++zaMnoziti;

        if(zaMnoziti <= 0)
        {
            resenje = 0LL;
            manje = true;
            return;
        }

        resenje = (resenje * zaMnoziti) % MOD;

        dfs(e, s, manje);
    }
}

ll modPow(ll a, ll n)
{
    if(n == 0)
        return 1LL;
    ll pola = modPow(a, n/2) % MOD;
    ll celo = (pola*pola) % MOD;

    if(n % 2 == 0)
    {
        return celo;
    }
    else
    {
        return (celo*a)%MOD;
    }
}

int main()
{
    cin >> n >> k;
    resenje = (ll)k;

    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1, false);

    cout << resenje << '\n';

    return 0;
}
