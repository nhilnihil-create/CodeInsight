#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout);
#define pb push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)

#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sd(x) scanf("%lf",&x);
#define pLL pair<long long,long long>
#define pDB pair<double,double>
#define ff first
#define sn second
#define PRINT_CASE  printf("Case %d: ",tc++)
#define PRINT_CASENL  printf("Case %d:\n",tc++)
//#define mx 100005
#define lnd tree[ind<<1]
#define rnd tree[(ind<<1)+1]
#define cnd tree[ind]
#define lndp b,(b+e)>>1,(ind<<1)
#define rndp ((b+e)>>1)+1,e,(ind<<1)+1
#define IN(a,x,y) (a>=x && a<=y)
#define popcountL __builtin_popcountll
#define popcount __builtin_popcount
/// int other=mask^((1<<n)-1);
typedef long long ll;
typedef long long int lln;
typedef pair<int,int> pii;
ll INF=1<<28;
//typedef long long lld;
const double PI=acos(-1.0);
//int fx[]={1,-1,0,0}; //direction array
//int fy[]={0,0,1,-1};
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int knight[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
const long double EPS=1e-7;
//#define INF 10000

//struct compare
//{
//  bool operator()(const int& l, const int& r)
//  {
//      return l>r;
//  }
//};

/////////////////////////////////////template sesh/////////////////////////////////////////////////////
///code goes from here
const int mx=100100;

int mod=1e9+7;
ll dp[mx][2][2];
string s;
ll bigmod(ll n,ll p,ll mod)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll a=bigmod(n,p/2,mod);
        return ((a%mod)*(a%mod))%mod;
    }
    else
    {
        ll a=bigmod(n,p-1,mod);
        return ((n%mod)*(a%mod))%mod;
    }
}
ll fun(int pos,int carry,int flag )
{
//    cout<<"carry "<<carry<<endl;
    if(carry)
        carry=1;
//    cout<<carry<<endl;
    if(pos==-1)
    {
        if(carry)
            return 0;
        if(flag)
            return 0;
        return 1;
    }
    ll &ret=dp[pos][carry][flag];
    if(ret!=-1)
        return ret;
    ret=0;
    int a,b,xorr;
    for(int i=0;i<4;i++)
    {
        a=(i&1);
        if(a)
            a=1;
        b=i&2;
        if(b)
            b=1;
        xorr=a^b;
        int sum=a+b+carry;
        if(xorr==((sum)&1))
        {
            if(s[pos]=='1')
            {
                if(xorr==0)
                ret+=fun(pos-1,sum&2,0);
                else
                ret+=fun(pos-1,sum&2,flag);
            }
            else
            {
                if(xorr==0)
                ret+=fun(pos-1,sum&2,flag);
                else
                ret+=fun(pos-1,sum&2,1);
            }
        }
        ret%=mod;
    }
//    cout<<"ok "<<endl;
    return ret;


}
int main()
{
    mem(dp,-1);
    cin>>s;
    ll ans=fun(s.size()-1,0,0);
//    ans*=bigmod(2LL,mod-2,mod);
    ans%=mod;
    cout<<ans<<endl;

    return 0;
}

