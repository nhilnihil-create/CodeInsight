#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ull unsigned long long
using namespace std;
const int maxx = 2007;
const ll mod1 = 1e7;
const ll mod = 1e9 + 7;
const ll base = 311;
const ll base1 = 113;
const ll maxn = 1e6 + 7;
bool check;
ll t, T, n, a[maxn], b[maxn], m1, m, tong, r, ans, mx, k, ma[maxx][maxx], pw[maxx][maxx];
//ll , c[maxx], st1[maxx];
//ll  , pw[maxx];
//string s[maxx], ss[maxx], str, f[maxx][10];
struct dang
{
    ll mn, gcd, val, pos, dd, n1, n2, n3;
};
ll f[maxx][maxx];
string s;
struct les
{
    bool operator()(ll x, ll y)
    {
        return x > y;
    }
};
dang c[maxn];
bool lt(const dang&x, const dang& y)
{
    return x.val > y.val;
}
deque<ll> st;
priority_queue<ll, vector<ll>, les >st1;
map<ll, ll> mp;
vector<ll> adj;
void sol()
{

    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i <= n; i ++)
        cin >> b[i];
    for(int i = 1; i <= n; i ++)
    {
        while(!st.empty() && b[st.back()] < b[i])st.pop_back();
        while(!st.empty() && b[st.front()] > a[i])st.pop_front();
        if(a[i] != b[i] && (st.empty() || b[st.back()] != b[i]))
        {
            ++ans;
            st.push_back(i);
        }
    }
    cout << ans;
}

void ntu()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> c[i].val;
        c[i].pos = i;
    }
    sort(c+1, c+1+n, lt);
    for(int i = 1; i <= n; i ++)
    {
        for(int lf = 0; lf <= i; lf ++)
        {
            int rt = i - lf;
            if(rt > 0) f[lf][rt] = max(f[lf][rt], f[lf][rt-1] + c[i].val * abs(n - rt + 1 - c[i].pos));
            if(lf > 0) f[lf][rt] = max(f[lf][rt], f[lf-1][rt] + c[i].val * abs(c[i].pos - lf));
            if(i == n)ans = max(f[lf][rt], ans);
        }
    }
    cout << ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //freopen("Test.INP", "r", stdin);
    ntu();
}
/*
3 4
0 3 -1 2
3 3 3 3
3 1 3 0
*/
