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
    string a;
    cin>>a;
    /*
    vector<lg>a(n,0);
    for(lg i=0;i<n;i++)
        cin>>a[i];
    */
    lg n=a.length();
    lg ans=0;
    for(lg i=0;i<n;i++)
        ans+=a[i]-48;
    if(ans%9==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
