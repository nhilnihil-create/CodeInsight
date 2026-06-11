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
#define                           eb                          emplace_back



using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}


 main()

{
    fast
    int n;
    cin>>n;
    vector<pi>ses;
    int one=__builtin_popcount(n);
    if(one==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(n<3)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int last=-1;
    int yo=n;
    if(n%2==0)
    {
        last=n;
        n=n-1;
    }
    f(i,2,n)
    {
        ses.eb(1,i);
        if(i%2==0)ses.eb(i,yo+i+1);
        else ses.eb(i,yo+i-1);
    }
    ses.eb(yo+2,yo+1);
    if(last!=(-1))
    {
        int x=0,y=0,cnt=0;
        for(int j=0;j<=35;j++)
        {
            if(last>>j & 1)
            {
                cnt++;
                if(cnt%2==0)x=x|(1LL<<j);
                else y=y|(1LL<<j);
            }
        }
        x=x|(1LL);
        ses.eb(x,last);
        ses.eb(y,2*last);
    }
    cout<<"Yes"<<endl;
    for(auto x:ses)
    {
        cout<<x.fi<<" "<<x.si<<endl;
    }
    return 0;
}
