#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,k;
ll a[200005];
int main()
{
cin>>n>>k;
for(int i=0;i<n;i++)
cin>>a[i];
ll l=0,r=1e9+5;
while(r-l>1)
{
ll mid=(l+r)/2;
ll t=0;
for(int i=0;i<n;i++)
t=t+(a[i]-1)/mid;

if(t<=k)r=mid;
else l=mid;

}
cout <<r;
}