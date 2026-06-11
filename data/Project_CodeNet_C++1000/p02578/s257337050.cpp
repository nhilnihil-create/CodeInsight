#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    lg n;
    cin>>n;
    vector<lg>a(n,0);
    for(lg i=0;i<n;i++)
        cin>>a[i];
    lg ans=0;
    lg maxnow=0;
    for(lg i=0;i<n;i++)
    {
        if(a[i]>=maxnow)
            maxnow=a[i];
        else
        {
            ans+=maxnow-a[i];
        }
    }
    cout<<ans<<endl;
}
