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

int main()
{

    string s,t;
    cin>>s>>t;
    lg l = s.length();
    lg ans=0;
    for(lg i=0;i<l;i++)
        if(s[i]!=t[i]) ans++;

    cout<<ans<<endl;

}
