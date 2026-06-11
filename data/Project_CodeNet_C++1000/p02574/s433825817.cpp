#include <bits/stdc++.h>
using namespace std;

#define INPUT freopen("input.txt", "r", stdin);

#define ll long long
#define ld long double

#define len(s) s.size()

#define fl(st, en, in) for (int i = st; i < en; i += in)
#define rfl(st, en, de) for (int i = st; i < en; i -= de)
#define ifl(st, en, in) for (int j = st; j < en; j += in)
#define fll fl(0, n, 1)

#define cy cout << "Yes" << endl;
#define cn cout << "No" << endl;
#define ci(s) cin >> s
#define co(s) cout << s << endl
#define nl cout << endl

#define vl vector<ll>
#define pb(x) push_back(x)

#define ms(arr, x) memset(arr, x, sizeof(arr))

#define inf INT_MAX
#define mx (ll)100000009
#define mod 1e9 + 7

//DSU

ll n, m;
ll par[mx];
ll sz[mx];

void make_set(ll v)
{
    par[v] = v;
    sz[v] = 1;
}

ll find_set(ll v)
{
    if (par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}

void union_set(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}
const string pc = "pairwise coprime";
const string sc = "setwise coprime";
const string nc = "not coprime";
const int A = 1e6 + 5;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(A);
    fll
    {
        cin >> a.at(i);
        c.at(a.at(i))++;
    }
    bool pairwise = true;
    fl(2, A, 1)
    {
        int cnt = 0;
        for (int j = i; j < A; j += i)
        {
            cnt += c.at(j);
        }
        if (cnt > 1)
            pairwise = false;
    }
    if (pairwise)
    {
        cout << pc << endl;
        return;
    }
    int g = 0;
    fll
    {
        g = gcd(g, a.at(i));
    }
    if (g == 1)
    {
        cout << sc << endl;
        return;
    }
    cout << nc << endl;
    return;
}

int main()
{
    // INPUT;
    // int t;
    // ci(t);
    // while (t--)
    solve();
}