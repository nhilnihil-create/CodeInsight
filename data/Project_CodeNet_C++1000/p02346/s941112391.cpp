#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5;
ll n,q;

ll seg[maxn*4+7];

void add(int id, int l, int r, int idx, int val)
{

    if(l+1 == r)
        {
            seg[id]+=val;
            return;
        }

    int mid=(l+r)/2;
    if(idx < mid)
        add(id*2, l, mid, idx, val);
    else
        add(id*2+1, mid, r, idx, val);

    seg[id]+=val;

}

ll ask(int id, int L, int R, int l, int r)
{
    if( l<=L && R<=r)
        return seg[id];

    int mid=(L+R)/2;
    ll x1=0,x2=0;

    if(r > mid)
        x1=ask(id*2+1 ,mid,R, max(l,mid), r);

    if(l<mid)
        x2=ask(id*2, L,mid, l, min(r,mid));

    return x1+x2;
}


int main()
{
    cin>>n>>q;
    while(q--)
    {
        int x,y;
        int type;
        cin>>type>>x>>y;
        if(type==0)
            add(1,1,n+1,x,y);
        else
            cout<<ask(1,1,n+1,x,y+1)<<endl;
    }
}