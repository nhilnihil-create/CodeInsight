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
    string s;
    cin>>s;
    lg len=0;
    lg ans=0;
    for(lg i=0;i<s.length();i++)
    {
        if(s[i]=='R') len++;
        else
        {
            ans=max(ans,len);
            len=0;
        }
    }
    ans=max(ans,len);

    cout<<ans<<endl;
}
