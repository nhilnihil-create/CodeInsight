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
int a[505];
int pre[505];
int suf[505];
int n,k;
int solve(int d)
{
    vector<int>vec;
    f(i,1,n)
    {
        int rem=a[i]%d;
        vec.pb(rem);
    }
    sort(vec.begin(),vec.end());
    int sum=0;
    int sz=vec.size();
    f(i,1,sz)
    {
        sum+=vec[i-1];
        pre[i]=sum;
    }
    sum=0;
    rf(i,sz,1)
    {
        sum+=(d-vec[i-1]);
        suf[i]=sum;
    }
    int ret=inf;
    f(i,1,sz)
    {
        int cost=max(pre[i],suf[i+1]);
        ret=min(ret,cost);
    }
    if(ret<=k)return true;
    return false;
}
 main()

{
    fast
    cin>>n>>k;
    int sum=0;
    f(i,1,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    vector<int>d;
    for(int i=1;i*i<=sum;i++)
    {
        if(sum%i==0)
        {
            d.pb(i);
            if((sum/i)!=i)
            {
                d.pb(sum/i);
            }
        }
    }
    int ses=inf;
    sort(d.rbegin(),d.rend());
    for(auto x:d)
    {
        if(solve(x)){
        cout<<x<<endl;
        return 0;
        }
    }


}



































