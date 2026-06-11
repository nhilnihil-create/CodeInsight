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
const int M=200005;
int a[M],b[M];
 main()

{
    fast
    int n;
    cin>>n;
    f(i,0,n-1)cin>>a[i];
    f(i,0,n-1)cin>>b[i];
    f(i,0,n-1)
    {
        if(b[i]<a[i])
        {
            cout<<"-1"<<endl;return 0;
        }
    }
    priority_queue<pi>pq;
    f(i,0,n-1)
    {
        if(a[i]!=b[i])pq.push(mp(b[i],i));
    }
    int ses=0;
    while(!pq.empty())
    {
        int y=pq.top().si;
        int x=(y-1+n)%n;
        int z=(y+1)%n;
        pq.pop();
        int cost=0;
        if(b[y]!=a[y] && b[y]>b[x] && b[y]>b[z])
        {
            cost=(b[y]-a[y])/(b[x]+b[z]);
            b[y]-=(cost*(b[x]+b[z]));
        }
        ses+=cost;
        if(b[y]!=a[y] && cost==0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        if(b[y]!=a[y])
        {
            pq.push(mp(b[y],y));
        }

    }
    f(i,0,n-1)
    {
        if(a[i]!=b[i])
        {
            cout<<"-1"<<endl;return 0;
        }
    }
    cout<<ses<<endl;
    return 0;

}

































