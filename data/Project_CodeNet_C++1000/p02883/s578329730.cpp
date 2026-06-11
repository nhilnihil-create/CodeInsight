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


vector<int>a,c;
int n,k;
bool chk(int lim)
{
    int baki=k;
    f(i,0,n-1)
    {
        int val=c[i]*a[i];
        if(val<=lim)continue;
        int p=(a[i]*c[i]-lim+c[i]-1)/c[i];
        if(p<=baki)
        {
            baki-=p;
        }
        else
        {
            return false;
        }

    }
    return true;
}
 main()

{
    fast
    cin>>n>>k;
    a.resize(n);
    c.resize(n);
    f(i,0,n-1)
    {
        cin>>a[i];
    }
    f(i,0,n-1)
    {
        cin>>c[i];
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int lo=0,hi=a[n-1]*c[0];
    int ans=hi;
    while(hi-lo>=2)
    {
        int mid=(lo+hi)>>1LL;
        if(chk(mid))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    f(i,lo,hi)
    {
        if(chk(i))
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
