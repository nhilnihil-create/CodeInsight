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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    s=s+s;
    int nxt[2*n+2][28];
    memset(nxt,-1,sizeof nxt);
    rf(i,2*n-1,0)
    {
        f(j,0,25)
        {
            nxt[i][j]=nxt[i+1][j];
        }
        nxt[i][s[i]-'a']=i;
    }
    int sz=t.size();
    int cur=0,cnt=0;
    f(i,0,sz-1)
    {
       int dan=nxt[cur][t[i]-'a'];
       if(dan==-1)
       {
           cout<<"-1"<<endl;
           return 0;
       }
       if(dan>=n)
       {
          cur=dan-n+1;
          cnt++;
       }
       else
       {
           cur=dan+1;
       }
       if(cur==n)
       {
           cur=0;
           cnt++;
       }
    }
    int ses=(cnt*n)+(cur);
    cout<<ses<<endl;
    return 0;

}



































