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

 main()

{
    fast
    int tmp,n;
    cin>>tmp;
    int k=tmp;
    n=(1LL<<tmp);
    multiset<int>s;
    f(i,1,n)
    {
        cin>>tmp;
        tmp=-tmp;
        s.insert(tmp);
    }
    vector<int>vec;
    vec.pb(*s.begin());
    s.erase(*s.begin());
    for(int i=1;i<=k;i++)
    {
          vector<int>nw;
          for(auto x:vec)
          {
               if(s.upper_bound(x)==s.end())
               {
                   cout<<"No"<<endl;
                   return 0;
               }
               nw.pb(*(s.upper_bound(x)));
               s.erase(s.upper_bound(x));
          }
          for(auto x:nw)
          {
              vec.pb(x);
          }
          sort(vec.begin(),vec.end());
    }
    cout<<"Yes"<<endl;
    return 0;

}


































