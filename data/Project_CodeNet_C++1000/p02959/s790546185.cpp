#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
#define lli                                 long long int
#define lb                                  long double
#define pi                                  acos(-1)
#define FindDistance(ax,ay,bx,by)           sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define gcd(a,b)                            __gcd(a,b)
#define lcm(a,b)                           (a/gcd(a,b))*b
#define T                                  int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define all(v)                             v.begin(),v.end()
#define pb                                 push_back
#define inf                                999999999999999
#define mod                                1000000007
#define maxn                               100003
#define FastIO                             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    FastIO;
    lli n,mon,i,x,ans=0;
    vector<lli>a,b;
    cin>>n;
    for(i=0;i<n+1;i++)
    {
        cin>>x;
        a.pb(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        b.pb(x);
    }
//    for(i=0;i<n-1;i++)
//    {
//        cin>>x;
//        c.pb(x);
//    }
    for(i=0;i<n;i++)
    {
        mon=min(a[i],b[i]);
        ans+=mon;
        b[i]-=mon;
        a[i]-=mon;
        mon=min(a[i+1],b[i]);
        ans+=mon;
        b[i]-=mon;
        a[i+1]-=mon;

    }
    cout<<ans<<endl;
    return 0;

}
