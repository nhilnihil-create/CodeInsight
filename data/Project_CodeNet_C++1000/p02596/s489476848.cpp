//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
     ll k;
     cin>>k;
     ll temp=7,ans=1;
     if(k%2==0)
     {
         cout<<"-1\n";
         return 0;
     }
     for(int i=1;i<100000000;i++)
     {
         temp=temp%k;
         if(temp==0)
         {
             cout<<ans<<endl;
             return 0;
         }
         ans++;
         temp=temp*10+7;
     }
     cout<<"-1\n";
     return 0;
}
