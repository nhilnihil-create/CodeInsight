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
     int n,k,p[5005],c[5005];
     cin>>n>>k;
     for(int i=0;i<n;i++)
     cin>>p[i],p[i]--;
     for(int i=0;i<n;i++)
     cin>>c[i];
     ll ans=-INT_MAX;
     for(int i=0;i<n;i++)
     {
         int now=i;
         ll c_sum=0,c_cnt=0;
         while(true)
         {
             c_cnt++;
             c_sum+=c[now];
             now=p[now];
             if(now==i)
             break;
         }
         ll sum=0,cnt=0;
         while(true)
         {
             cnt++;
             sum+=c[now];
             if(cnt>k)
             break;
             ll temp=(k-cnt)/c_cnt;
             temp=sum+max(0ll,c_sum)*temp;
             ans=max(ans,temp);
             now=p[now];
             if(now==i)
            break;
         }
     }
     cout<<ans<<endl;
}
