#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 

const ll M=1e5+5;
ll a[M],seg[4*M],pge[M],nge[M];

void build(ll idx , ll st , ll en)
{
    if(st==en)
      seg[idx]=a[st];
    else
    {
        ll mid = (st+en)/2;
        build(2*idx+1,st,mid);
        build(2*idx+2,mid+1,en);
        seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    }

    return;
}

ll query(ll idx,ll st,ll en,ll l,ll r)
{

    if(st>r || en<l || l>r)
        return -1;

    if(st>=l && en<=r)
      return seg[idx];

    ll mid = (st + en)/2;
    return max(query(2*idx+1,st,mid,l,r),query(2*idx+2,mid+1,en,l,r));            
}

void update(ll idx, ll st,ll en , ll pos,ll val)
{
      ll mid = (st+en)/2;
      if(st==en)
      {
          seg[idx]=val;
          return;
      }
      if(pos<=mid)
        update(2*idx+1,st,mid,pos,val);
      else
        update(2*idx+2,mid+1,en,pos,val);

      seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);

      return;
}

void pre(ll n)
{
    ll i;
    stack<ll>s;
    for(i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            nge[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        nge[s.top()]=n,s.pop();

    for(i=n-1;i>=0;i--)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            pge[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        pge[s.top()]=-1,s.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,j,k,x,y,t,m;

    cin >> n;
    for(i=0;i<n;i++)
      cin >> a[i];

    build(0,0,n-1);
    pre(n);    
    long long ans=0;
    for(i=0;i<n;i++)
    {
        ll pg=pge[i],ng=nge[i],spg=-1,sng=n;

        if(pg!=-1)
        {
            update(0,0,n-1,pg,-1);

            ll lo=0,hi=pg,md,prev=-1;
            while(lo<=hi)
            {
                md=(lo+hi)/2;
                if(md==prev)
                  break;
                prev=md;
                x=query(0,0,n-1,md,i);
                if(x==a[i])
                  hi=md;
                else
                  lo=md+1;
            }
            spg=hi-1;

            update(0,0,n-1,pg,a[pg]);
        }

        if(ng!=n)
        {
            update(0,0,n-1,ng,-1);

            ll lo=ng,hi=n-1,md,prev=-1;
            while(lo<=hi)
            {
                md=(lo+hi)/2;
                if(md==prev)
                {
                  if(query(0,0,n-1,i,hi)==x)
                    lo=hi;
                  break;
                }
                prev=md;
                x=query(0,0,n-1,i,md);
                if(x==a[i])
                  lo=md;
                else
                  hi=md-1;

            }
            sng=lo+1;
            update(0,0,n-1,ng,a[ng]);
        }

        long long subs = 0;
        subs += (ng-i)*(pg-spg) + (i-pg)*(sng-ng);
        ans+=(subs)*a[i];
    }
    cout<<ans<<endl;  
    return 0;
}