///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

#define                           ll                          long long
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
int rgt_dp[M][2];
int lft_dp[M][2];
set<int>::iterator lo,hi,it;
char zs[M+3];
 main()

{
    int n,k,c;
    scanf("%d%d%d",&n,&k,&c);
    string ss;
    scanf("%s",zs);
    ss=zs;
    if(ss[0]=='o')lft_dp[0][1]=1;
    f(i,1,n-1)
    {
        lft_dp[i][0]=max(lft_dp[i-1][1],lft_dp[i-1][0]);
        int x=0;
        if(i-c-1>=0)x=max(lft_dp[i-c-1][0],lft_dp[i-c-1][1]);
        if(ss[i]!='x')lft_dp[i][1]=x+1;
    }
    rf(i,n-1,0)
    {
        rgt_dp[i][0]=max(rgt_dp[i+1][1],rgt_dp[i+1][0]);
        int x=0;
        if(i+c+1<n)x=max(rgt_dp[i+c+1][0],rgt_dp[i+c+1][1]);
        if(ss[i]!='x')rgt_dp[i][1]=x+1;
    }
    set<int>s;
    f(i,0,n-1)s.insert(i);
    bool vis[n+2];clr(vis);
    rf(i,n-1,0)
    {
        if(rgt_dp[i][0]>=k || rgt_dp[i][1]>=k)
        {
            f(j,0,i-1)
            {
                vis[j]=1;
                s.erase(j);
            }
            break;
        }
    }
    f(i,0,n-1)
    {
        if(lft_dp[i][0]>=k || lft_dp[i][1]>=k)
        {
            f(j,i+1,n-1)
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    s.erase(j);
                }
            }
            break;
        }
    }
    f(i,0,n-1)
    {
        int l=i;
        int r=i+c+1;
        if(r>=n)continue;
        int lmx=max(lft_dp[l][0],lft_dp[l][1]);
        int rmx=max(rgt_dp[r][0],rgt_dp[r][1]);
        int sum=lmx+rmx;
        if(s.size()==0)break;
        if(sum>=k)
        {
            lo=s.upper_bound(l);
            hi=s.lower_bound(r);
            if(hi!=s.begin() && lo!=s.end())
            {
                 hi--;
                 int lft=*lo;
                 int rgt=*hi;
                 if(lft<=rgt)
                 {
                     it=lo;
                     vector<int>tmp;
                     while(1)
                     {
                         tmp.pb(*it);
                         if(it==hi)break;
                         it++;
                     }
                     for(auto x:tmp)s.erase(x);
                 }
            }
        }
    }
    if(c==0)
    {
         f(i,0,n-1)
    {
        int l=i;
        int r=i+2;
        if(r>=n)continue;
        int lmx=max(lft_dp[l][0],lft_dp[l][1]);
        int rmx=max(rgt_dp[r][0],rgt_dp[r][1]);
        int sum=lmx+rmx;
        if(s.size()==0)break;
        if(sum>=k)
        {
            lo=s.upper_bound(l);
            hi=s.lower_bound(r);
            if(hi!=s.begin() && lo!=s.end())
            {
                 hi--;
                 int lft=*lo;
                 int rgt=*hi;
                 if(lft<=rgt)
                 {
                     it=lo;
                     vector<int>tmp;
                     while(1)
                     {
                         tmp.pb(*it);
                         if(it==hi)break;
                         it++;
                     }
                     for(auto x:tmp)s.erase(x);
                 }
            }
        }
    }
    }
    for(auto x:s)
    {
        if(ss[x]=='o')
        {
            printf("%d\n",x+1);
        }
    }
    return 0;

}


































