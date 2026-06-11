
/***

   Author : Md. Jashim Uddin
   From   : RMSTU

 ***/
#include<bits/stdc++.h>
using namespace std;
#define     sf(a)           scanf("%d",&a)
#define     sff(a,b)        scanf("%d %d",&a,&b)
#define     sfff(a,b,c)     scanf("%d %d %d",&a,&b, &c)
#define     pb              push_back
#define     ll              long  long int
#define     fast            ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define     pi              2*acos(0)
#define     sp              fixed<<setprecision
#define     lcm(a,b)        (a*b)/gcd(a,b)
#define     gcd(a,b)        _gcd(a,b)
#define     forn(i,n)       for(int i=1;i<=n;i++)
#define      mx               10001
int main()
{

    string s;
    cin>>s;
    string ss;
    cin>>ss;
    ll c=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==ss[i])c++;
    }
    cout<<c<<endl;

    return 0;
}
