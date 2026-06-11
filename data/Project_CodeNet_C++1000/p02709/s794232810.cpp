#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fill(x, v) memset(x, v, sizeof(x))
const ll mod = 1000000007;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
/*
std::cout << std::setprecision(9) << f << '\n';//3.141590000;
map<char,int>::reverse_iterator rit;
*/
// --------dsu-- --------
vector<int> volume(1000000);
vector<int> parent(1000000);

void initialise_dsu()
{
    for (int i = 0; i < volume.size(); i++)
        volume[i] = 1;
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;
}

int find_par(int v)
{
    return (v == parent[v] ? v : parent[v] = find_par(parent[v]));
}

void union_sets(int a, int b)
{
    a = find_par(a);
    b = find_par(b);
    if (a != b)
    {
        if (volume[a] < volume[b])
            swap(a, b);
        parent[b] = a;
        volume[a] += volume[b];
    }
}

int power(int x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
//-----------------------------

const int N = 2e3 + 10;
ll dp[N][N];
pll a[N];

int n;
ll solve(ll L, ll R)
{
    if (L > R)
        return 0;
    ll &ret = dp[L][R];
    if (ret >= 0)
        return ret;
    int pos = L + n - 1 - R;
    ret = 1LL * abs(a[pos].second - L) * a[pos].first + solve(L + 1, R);
    ret = max(ret, 1LL * abs(a[pos].second - R) * a[pos].first + solve(L, R - 1));
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater<pll>());
    memset(dp, 255, sizeof(dp));
    ll ret = solve(0, n - 1);
    cout << ret << endl;
    return 0;
}
