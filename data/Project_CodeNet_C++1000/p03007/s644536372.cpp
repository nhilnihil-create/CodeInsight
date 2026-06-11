///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
int a[M],pos=0,neg=0;
vector<int>p,n;
vector<pi>ses;
void two()
{
    int x=a[1];
    int y=a[2];
    int op1=x-y;
    int op2=y-x;
    if(op1>op2)
    {
        cout<<op1<<endl;
        cout<<x<<" "<<y<<endl;
    }
    else
    {
        cout<<op2<<endl;
        cout<<y<<" "<<x<<endl;
    }
    exit(0);
}
void only_pos()
{
    sort(p.begin(),p.end());
    int x=p[0];
    int sz=p.size();
    for(int i=1;i<sz-1;i++)
    {
        int y=p[i];
        ses.pb(mp(x,y));
        x=x-y;
    }
    ses.pb(mp(p[sz-1],x));
    x=p[sz-1]-x;
    cout<<x<<endl;
    for(auto z:ses)
    {
        cout<<z.fi<<" "<<z.si<<endl;
    }
    exit(0);
}
void only_neg()
{
    sort(n.begin(),n.end());
    int sz=n.size();
    int x=n[sz-1];
    for(int i=0;i<sz-1;i++)
    {
        int y=n[i];
        ses.pb(mp(x,y));
        x=x-y;
    }
    cout<<x<<endl;
    for(auto z:ses)
    {
        cout<<z.fi<<" "<<z.si<<endl;
    }
    exit(0);
}
void work()
{
    sort(p.begin(),p.end());
    sort(n.begin(),n.end());
    int x=n[0];
    for(int i=0;i<pos-1;i++)
    {
        int y=p[i];
        ses.pb(mp(x,y));
        x=x-y;
    }
    int y=p[pos-1];
    ses.pb(mp(y,x));
    y=y-x;
    for(int i=1;i<neg;i++)
    {
        int x=n[i];
        ses.pb(mp(y,x));
        y=y-x;
    }
    cout<<y<<endl;
    for(auto z:ses)
    {
        cout<<z.fi<<" "<<z.si<<endl;
    }

}
 main()

{
    fast
    int t;
    cin>>t;
    f(i,1,t)
    {
        cin>>a[i];
        if(a[i]>=0)pos++,p.pb(a[i]);
        else neg++,n.pb(a[i]);
    }
    if(t==2)two();
    if(neg==0)only_pos();
    if(pos==0)only_neg();
    work();
    return 0;

}



































