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
const int M=300005;
int cnt[M],tmp,abr_cnt[M];
int fx[M];
int pcnt[M],pabr_cnt[M];
int ses[M];
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n)
    {
        cin>>tmp;
        cnt[tmp]++;
    }
    f(i,1,n)
    {
        abr_cnt[cnt[i]]++;
    }
    int sum=0;
    f(i,1,n)
    {
        sum+=(abr_cnt[i]*i);
        pcnt[i]=sum;
    }
    sum=0;
    f(i,1,n)
    {
        sum+=abr_cnt[i];
        pabr_cnt[i]=sum;
    }
    f(x,1,n)
    {
       int lft=pcnt[x];
       int rgt=(pabr_cnt[n]-pabr_cnt[x])*x;
       fx[x]=(lft+rgt)/x;
       ses[fx[x]]=max(ses[fx[x]],x);
    }
    rf(i,n,1)
    {
        ses[i]=max(ses[i],ses[i+1]);
    }
    f(i,1,n)
    {
        cout<<ses[i]<<" ";
    }
    cout<<endl;
    return 0;

}

































