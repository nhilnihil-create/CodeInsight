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

int n,a,b,c,d;
string s;
void bye()
{
    cout<<"No"<<endl;
    exit(0);
}
bool chk(int x,int y)
{
    f(i,x,y-1)
    {
        if(s[i]=='#' && s[i+1]=='#')return false;
    }
    return true;
}
bool chk2(int x,int y)
{
    f(i,x,y-2)
    {
        if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.')return true;
    }
    return false;
}
 main()

{
    fast
    cin>>n>>a>>b>>c>>d;
    cin>>s;
    s="#"+s;
    if(c==d)bye();
    if(!chk(a,c))bye();
    if(!chk(b,d))bye();
    if(c<d)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(chk2(b-1,d+1))
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;

}



































