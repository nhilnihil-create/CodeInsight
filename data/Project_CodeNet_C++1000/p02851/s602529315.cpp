#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxx = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll base = 311;
const ll base1 = 113;
ll t, T, n, m, k, tong, r, ans, mx, mn, x, y;
string s, s1, s2, ss;
ll a[maxx], b[maxx], pw[maxx], pw1[maxx], st[maxx], st1[maxx];
bool check(ll v)
{
    if(v < 2)return false;
    for(int i = 2; i <= v / i; i ++)
        if(v % i == 0)return false;
    return true;
}
ll hs(ll hh[maxx], ll pw[maxx], ll i, ll j)
{
    return (hh[j] - hh[i-1] * pw[j - i + 1] + maxx * maxx) % maxx;
}
struct mm
{
    ll val;
    ll pos;
};
mm c[maxx];
bool lf(const mm &x, const mm &y)
{
    return (x.val < y.val) || (x.val == y.val && x.pos < y.pos);
}
void sol()
{
    cin >> n >> k;
    ans = 0;
    b[0] = 0;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        a[i] %= k;
        b[i] = b[i-1] + a[i];
    }
    c[0].val = 0;
    c[0].pos = 0;
    for(int i = 1; i <= n; i ++)
    {
        //
        //if(b[i] == i)++ans;
        c[i].val = (b[i] - i + k) % k;
        c[i].pos = i;
      //cout << c[i].val <<" ";
    }
    //cout << '\n';
    sort(c, c+1+n, lf);
    for(int i = 0; i <= n; i ++)
    {
        t = 1;
        queue<ll> st;
        st.push(c[i].pos);
        while(c[i].val == c[i+1].val && i + 1 <= n)
        {
            ++i;
            while(!st.empty() && c[i].pos - st.front() >= k)
            {
                --t;
                st.pop();
            }
            st.push(c[i].pos);
            ans += t;
     //       cout << t<<" ";
            ++t;
        }
    }
    cout <<ans;

}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    sol();
}
/*
using namespace std;
const ll maxn=3e5+1;
const ll maxx=1e13;
const ll mod=1e9+7;
const ll mod1=998244353;

//vector <ll> adj[maxn];
set<ll> adj1[maxn];
//vector<ll> ans;
//bool kt[maxn];
ll n,m,e,k;
ll d=0;
set<ll> pt;
set<ll> adj[maxn];
ll cnt=0;
void dfs(ll u)
{
    cnt++;
    pt.erase(pt.find(u));
    ll pre=0;
    auto it=pt.begin();
    while (it!=pt.end())
    {
        it=pt.upper_bound(pre);
        while (adj[u].find(*it)!=adj[u].end()&&it!=pt.end())
        {
            it++;
        }
        if ( it!=pt.end() )
        {
            pre=*it;
            dfs(*it);
        }
    }
}
int main()
{
    // freopen("test.txt","r",stdin);
    // freopen("CHEMIST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);


    }
    for (int i=1;i<=n;i++)pt.insert(i);
    vector<ll> ans;
    for (int i=1;i<=n;i++)
    {
        if (pt.find(i)!=pt.end())
        {
            cnt=0;
            dfs(i);
            ans.pb(cnt);
        }
    }
    sort(all(ans));
    cout <<ans.size()<<endl;
    for (auto p:ans)
    {
        cout <<p<<" ";
    }

}
*/
