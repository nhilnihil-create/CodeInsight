/*
h s, d't skp th si tll i's svedclTabCtrl
 * ABC141 E
 * ABC145 D
 * ABC147 F
 * ABC174 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll a[10000005]={};
int main()
{
ll n;
cin>>n;
ll ans=0;
for(int i=1;i<=n;i++)
{
ans+=(a[i]+1)*i;
ll w=2;
while(i*w<=n)
{
a[i*w]++;
w++;
}
}
cout<<ans<<endl;
}
/*
 *||||

 */