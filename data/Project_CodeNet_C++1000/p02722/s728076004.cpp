///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}


 main()

{
    fast
    int n;
    set<int>s;
    cin>>n;
    int yo=n-1;
    for(int i=1;i*i<=yo;i++)
    {
         if(yo%i==0)
         {
             s.insert(i);
             s.insert(yo/i);
         }
    }
    vector<pi>div;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int x=i;
            int y=n/i;
            div.pb(mp(x,y));
        }
    }
    int sz=div.size();
    f(i,0,sz-1)
    {
        int x=div[i].fi;
        int y=div[i].si;
        while(x%y==0 && x>=1)
        {
            x=x/y;
        }
        if(x%y==1)s.insert(y);
        x=div[i].si;
        y=div[i].fi;
         while(x%y==0 && x>=1)
        {
            x=x/y;
        }
        if(x%y==1)s.insert(y);

    }
    cout<<s.size()<<endl;
    return 0;

}











