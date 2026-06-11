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
     int n,m,k;
     string s[8];
     cin>>n>>m>>k;
     for(int i=0;i<n;i++)
     cin>>s[i];
     int ans=0;
     for(int i=0;i<(1<<n);i++)
     {
         for(int j=0;j<(1<<m);j++)
         {
             int sum=0;
             for(int x=0;x<n;x++)
                for(int y=0;y<m;y++)
             {
                 if(!((1<<x)&i)&&!((1<<y)&j)&&s[x][y]=='#')
                    ++sum;
             }
             if(sum==k)
             ++ans;
         }
     }
     cout<<ans<<endl;
}
