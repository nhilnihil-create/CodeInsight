#include<bits/stdc++.h>
using namespace std;

#define                      ff                                          first
#define                      ss                                          second
#define                      pai                                         acos(-1)
#define                      ll                                          long long
#define                      pb                                          push_back
#define                      mp                                          make_pair
#define                      pll                                         pair<ll,ll>
#define                      sz(a)                                       (ll)a.size()


double dis(double x,double y)
{
    return sqrt((x*x)+(y*y));
}
int  main(int argc, char const *argv[])
{
    ll i,j,k,a,b,c,d,n,m,t,h,u,v,x,y,z;
    cin>>n>>m;
    ll cnt=0;
    while(n--)
    {
        cin>>x>>y;
        if(dis(x,y)<=m)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

