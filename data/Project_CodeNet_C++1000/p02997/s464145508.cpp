///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

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
const int M=100009;
int fnd(int n)
{
    int ret=(n*(n-1))/2;
    return ret;
}
 main()

{
    fast
    int n,k;
    cin>>n>>k;
    int hi=fnd(n-1);
    if(k>hi)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<pi>vec;
    f(i,2,n)
    {
        vec.pb(mp(1,i));
    }
    for(int x=2;x<=n-1;x++)
    {
        for(int y=x+1;y<=n;y++)
        {
            if(hi==k)break;
            vec.pb(mp(x,y));
            hi--;
        }
        if(hi==k)break;
    }
    cout<<vec.size()<<endl;
    for(auto x:vec)
    {
        cout<<x.fi<<" "<<x.si<<endl;
    }
    return 0;

}



































