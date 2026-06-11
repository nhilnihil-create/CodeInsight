#include<bits/stdc++.h>
#define mxn 200005
#define ll long long
using namespace std;
ll seg[4*mxn], lazy[4*mxn];
vector<int>adj[mxn];
void propagate(int n, int s, int e)
{
    lazy[n*2]+= lazy[n];
    lazy[n*2 +1]+= lazy[n];
    int mid= (s+e)>>1;
    seg[n*2]+= lazy[n]*(mid-s+1);
    seg[n*2 +1]+= lazy[n]*(e-mid);
    lazy[n]= 0;
    return;
}
void update(int n, int s, int e, int l, int r, int val)
{
    if(s>=l && e<=r)
    {
        seg[n] += val*(e-s+1);
        lazy[n]+= val;
        return;
    }
    if(s>r || e<l)return;
    if(lazy[n])propagate(n, s, e);
    int mid= (s+e)>>1;
    update(n*2, s, mid, l, r, val);
    update(n*2 +1, mid+1, e, l, r, val);
    seg[n]= seg[n*2]+seg[n*2 +1];
    return;
}
ll query(int n, int s, int e, int l, int r)
{
    if(s>=l && e<=r)return seg[n];
    if(s>r || e<l)return 0;
    if(lazy[n])propagate(n, s, e);
    int mid= (s+e)>>1;
    return query(n*2, s, mid, l, r)+query(n*2 +1, mid+1, e, l, r);
}
int main()
{
    int n, x, y;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll res= 0;
    for(int i=1; i<=n; i++)
    {
        vector<int>vec;
        for(int j=0; j<adj[i].size(); j++)
        if(adj[i][j]<i)vec.push_back(adj[i][j]);
        sort(vec.begin(), vec.end());
        int lst= i, c= 1;
        for(int j=vec.size()-1; j>=0; j--)
        update(1, 1, n, vec[j]+1, lst, c), lst= vec[j], c--;
        update(1, 1, n, 1, lst, c);
        res+= query(1, 1, n, 1, n);
    }
    printf("%lld\n", res);
    return 0;
}
