#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N = 1e6, inf = 1e9;
ll tree[2 * N], lazy[2 * N], ar[N];
void pushDown(ll node, ll s, ll e)
{
    if(lazy[node])
    {
        ll l = 2 * node, r = 2 * node + 1;
        if( s != e)
        {
            ll mid = (s + e)/2;
            tree[l] += lazy[node];
            tree[r] += lazy[node];
            lazy[l] += lazy[node];
            lazy[r] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void build(ll node, ll s, ll e)
{
    lazy[node] = 0;
    if(s == e)
    {
        tree[node] = ar[s];
        lazy[node] = 0;
        return;
    }
    ll l = 2 * node, r = 2 * node + 1, m = (s + e)/2;
    build(l, s, m);
    build(r, m + 1, e);
    tree[node] = min(tree[l], tree[r]);
}
void update(ll node, ll s, ll e, ll i, ll j, ll val)
{
    pushDown(node, s, e);
    if(e < i || s > j) return ;
    if(s >= i && e <= j)
    {
        lazy[node] += val;
        tree[node] += val;
        cerr<<i<<" "<<j<<" "<<s<<" "<<e<<" "<<node<<" "<<tree[ node ]<<"\n";
        pushDown(node, s, e);
        return;
    }
    ll l = 2 * node, r = 2 * node + 1, m = (s + e)/2;
    update(l, s, m, i, j, val);
    update(r, m + 1, e, i, j, val);
    tree[node] = min(tree[l], tree[r]);
}
ll query(ll node, ll s, ll e, ll i, ll j)
{
    pushDown(node, s, e);
    if(e < i || s > j) return inf;
    if(s >= i && e <= j)
    {
        return tree[node];
    }
    ll l = 2 * node, r = 2 * node + 1, m = (s + e)/2;
    ll x = query(l, s, m, i, j);
    ll y = query(r, m + 1, e, i, j);
    return min(x, y);
}
int main()
{

    ll n, k;
    cin>>n>>k;
    if(k == 1)
    {
        cout<<0<<"\n";
    }
    else
    {
        cout<<n - k<<"\n";
    }
    return 0;
}
