#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ull unsigned long long
using namespace std;
const int maxx = 1002;
const ll mod = 1e9 + 7;
const ll base = 311;
const ll base1 = 113;
const ll maxn = 1e6 + 7;
bool check;
ll t, T, n, a[maxn], b[maxn], m1, m, tong, r, ans, mx, k, f[maxn], ma[maxx][maxx], pw[maxn];
//ll , c[maxx], st1[maxx];
//ll  , pw[maxx];
//string s[maxx], ss[maxx], str, f[maxx][10];
struct dang
{
    ll mn, gcd, val, pos, dd;
};
string s;
struct les
{
    bool operator()(ll x, ll y)
    {
        return x > y;
    }
};
dang c[maxn];
deque<ll> st;
priority_queue<ll, vector<ll>, les >st1;
map<ll, ll> mp;
vector<ll> adj;
bitset<50> fa;
ll tinh(ll i, ll j)
{
    return (f[j] - f[i-1]*pw[j-i+1] + mod * mod)%mod;
}
void sol()
{
    cin >> n >> s;
    ans = 0;
    s = " " + s;
    pw[0] = 1;
    for(int i = 1; i <= n / 2; i ++)
    {
        pw[i] = (pw[i-1] * base)%mod;
    }
    for(int i = 1; i <= n; i ++)
    {
        f[i] = (f[i-1] * base + s[i] - 'a' + 1) % mod;
    }
    ll lf = 0, rt = n / 2, mid;
    while(lf <= rt)
    {
        mid = (lf + rt) / 2;
        check = false;
        for(int i = 1; i <= n - mid; i ++)
        {
            for(int j = i + mid; j <= n - mid + 1; j ++)
            {
                if(tinh(i, i + mid - 1) == tinh(j, j + mid - 1))
                {
                    check = true;
                    break;
                }
            }
        }
        if(check)lf = mid + 1;
        else rt = mid - 1;
    }
    cout << rt;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //freopen("Test.INP", "r", stdin);
    sol();
}
