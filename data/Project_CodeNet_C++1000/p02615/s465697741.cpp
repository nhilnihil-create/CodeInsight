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
    lg ans=0;
    for(lg i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    ans+=a[n-1];
    lg k=n-2;
    lg i=n-2;
    while(k>0)
    {
        ans+=a[i];
        k--;
        if(k==0) break;
        ans+=a[i];
        k--;
        if(k==0) break;
        i--;
    }
    cout<<ans<<endl;
}
