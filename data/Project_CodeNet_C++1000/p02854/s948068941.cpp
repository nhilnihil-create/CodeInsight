/*
ID: lalitkumar__
TASK: B
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
//	freopen("beads.in","r",stdin);
//	freopen("beads.out","w",stdout);

ll n ;
 cin>>n;
 ll a[n];
 for(int i  = 0;i<n;i++) cin>>a[i];
 ll pre[n];
 pre[0] = a[0];
 for(int i = 1;i<n;i++)
 {
 	pre[i]=pre[i-1]+a[i];
 }
ll ans = INT_MAX;
for(int i =0;i<n;i++)
{
	ans = min(ans,abs(pre[i]-abs(pre[n-1]-pre[i])));
}
cout<<ans<<endl;
}