
/* Bismillahir Rahmanir Rahim */
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<string>
#define   mod          1000000007
#define   lp(i,n)      for(int i=1;i<=n;i++)
#define   lpp(i,a,b)    for(int i=a,i<=b;i++)
#define   stlp(i,n)    for(int i=0;i<n;i++)
#define   ll           long long int
#define   ull          unsigned long long int
#define   tst          int t;cin>>t;while(t--)
#define   pb           push_back
#define   vi           vector<int>v
#define   vs           vector<string>v
#define   rslt(x)      cout<<x<<endl;
#define   mp(x,y)      make_pair(x,y)
#define   yes          rslt("yes")
#define   YES          rslt ("YES")
#define   Yes          rslt ("Yes")
#define   srt(v)       sort(v.begin(),v.end())
#define   gcd(a,b)     __gcd(a,b)
#define   lcm(a,b)     (a*gcd(a,b))/b
#define   max          1000007
#define   str          int s[200000]

using namespace std;
int main()
{
    ll x,y,z;
    cin>>x>>y>>z;
    ll a = x/y;
    if(x%y)
        a++;
    cout<<a*z<<endl;




    return 0;
}
