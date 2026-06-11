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
int dp[M+4];
int nxt[M+4];
 main()

{
    fast
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    f(i,1,n)
    {
        if(s[i]=='1')dp[i]=inf;
    }
    dp[n]=0;
    set<pi>yo;
    yo.insert(mp(dp[n],n));
    rf(i,n-1,0)
    {
        if(s[i]=='1')
        {
            yo.insert(mp(dp[i],i));
            continue;
        }
        int lft=i+1,rgt=min(i+m,n);
        while(1)
        {
            pi chk=*yo.begin();
            if(chk.si>rgt)
            {
                yo.erase(yo.begin());
            }
            else break;
        }
        pi x=*yo.begin();
        dp[i]=1+dp[x.si];
        nxt[i]=x.si;
        yo.insert(mp(dp[i],i));
    }
    if(dp[0]>=inf)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int cur=0;
    while(1)
    {
        int x=nxt[cur];
        int gap=x-cur;
        cout<<gap<<" ";
        cur=x;
        if(cur==n)break;
    }
    cout<<endl;
    return 0;

}



































