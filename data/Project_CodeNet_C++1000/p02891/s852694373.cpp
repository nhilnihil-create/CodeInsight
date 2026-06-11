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
    int k;
    string s;
    cin>>s;
    cin>>k;
    vector<int>yo;
    int cnt=0;
    int sz=s.size();
    int len=sz;
    s=s+"#";
    int ses=0;
    f(i,0,sz-1)
    {
        if(s[i]==s[i+1])
        {
            cnt++;
        }
        else
        {
            cnt++;
            ses+=(cnt/2);
            yo.pb(cnt);
            cnt=0;
        }
    }
    if(k==1)
    {
        cout<<ses<<endl;
        return 0;
    }
    sz=yo.size();
    if(sz==1)
    {
        ses=(k*len)/2;
        cout<<ses<<endl;
        return 0;
    }
    int st=yo[0];
    int en=yo[sz-1];
    if(s[0]!=s[len-1])
    {
        cout<<ses*k<<endl;
        return 0;
    }
    if(st%2==0 || en%2==0)
    {
        cout<<ses*k<<endl;
    }
    else
    {
        cout<<ses*k+(k-1)<<endl;
    }
    return 0;

}



































