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
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


 main()

{
    fast
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    int ses[h+2][w+3];
    f(j,1,a)
    {
        f(i,1,h)
        {
            if(i<=b)ses[i][j]=0;
            else ses[i][j]=1;
        }
    }
     f(j,a+1,w)
    {
        f(i,1,h)
        {
            if(i<=b)ses[i][j]=1;
            else ses[i][j]=0;
        }
    }
    f(i,1,h)
    {
        f(j,1,w)
        {
            cout<<ses[i][j];
        }
        cout<<endl;
    }
    return 0;

}



































