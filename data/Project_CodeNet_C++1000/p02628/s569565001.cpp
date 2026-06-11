#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007


using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
lg n,m,k,ans;
int main()
{
    cin>>n>>k;
    vector<lg>p(n,0);
    for(lg i=0;i<n;i++)
        cin>>p[i];

    sort(p.begin(),p.end());
    ans=0;
    for(lg i=0;i<k;i++)
        ans+=p[i];
    cout<<ans<<endl;
}
