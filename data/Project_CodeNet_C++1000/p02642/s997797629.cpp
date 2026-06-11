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
int vc[1000000+5]={};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
vc[a[i]]+=1;
}
int ans=0;
for(int i=0;i<n;i++)
{
bool ok=1;
vc[a[i]]--;
for(int j=1;j<=sqrt(a[i]);j++)
{
if(a[i]%j==0)
{
if(vc[j] || vc[a[i]/j])
{
ok=0;
break;
}
}
}
vc[a[i]]++;
ans+=ok;
}
cout<<ans<<endl;
}
/*
 *||||

 */
