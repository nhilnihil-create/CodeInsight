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
int gcd(int a,int b)
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
     int n;
     string s;
     cin>>n>>s;
     int i=0,j=n-1,ans=0;
     while(i<j)
     {
         if(s[i]=='W')
         {
             while(j>i)
             {
                 if(s[j]=='R')
                 {
                     swap(s[i],s[j]);
                     ++ans;
                     break;
                 }
                 --j;
             }
         }
         ++i;
     }
     cout<<ans<<endl;
}
