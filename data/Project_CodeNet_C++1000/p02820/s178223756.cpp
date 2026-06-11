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
#define   P 2
#define   S 3
#define   R 4
using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;

 main()

{
    fast
    int n,k,r,s,p;
    cin>>n>>k>>r>>s>>p;
    string a;
    cin>>a;
    int last[n+2];
    memset(last,-1,sizeof last);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i-k>=0)
        {
             if(a[i]=='r')
             {
                 if(last[i-k]==P)
                 {
                     last[i]=-1;
                 }
                 else
                 {
                     sum+=p;
                     last[i]=P;
                 }
             }
             else if(a[i]=='p')
             {
                   if(last[i-k]==S)
                 {
                     last[i]=-1;
                 }
                 else
                 {
                     sum+=s;
                     last[i]=S;
                 }
             }
             else
             {
                  if(last[i-k]==R)
                 {
                     last[i]=-1;
                 }
                 else
                 {
                     sum+=r;
                     last[i]=R;
                 }
             }
        }
        else
        {
            if(a[i]=='r')sum+=p,last[i]=P;
            else if(a[i]=='p')sum+=s,last[i]=S;
            else sum+=r,last[i]=R;
        }
    }
    cout<<sum<<endl;
    return 0;

}



































