#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
     ll n;
     cin>>n;
     ll ar[n];
     ll su = 0;
     for(int i=0;i<n;i++)
     {
     	cin>>ar[i];
     	su+=ar[i];
     }
     ll avg = su/n;
     ll avg1 = avg+1;
     ll avg2 = avg-1;
     ll ans1 = 0,ans2=0,ans=0;
     for(int i=0;i<n;i++)
     {
     	ll dif = abs(avg-ar[i]);
     	ans+=pow(dif,2);
     }
     for(int i=0;i<n;i++)
     {
     	ll dif1 = abs(avg1-ar[i]);
     	ans1+=pow(dif1,2);
     }
     for(int i=0;i<n;i++)
     {
     	ll dif2 = abs(avg2-ar[i]);
     	ans2+=pow(dif2,2);
     }
     ll fin = min({ans,ans1,ans2});
     cout<<fin<<"\n";
}