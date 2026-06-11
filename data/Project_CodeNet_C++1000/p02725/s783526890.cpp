#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=1100,M=1001001;
ll n,m,T,cnt,f[N][N],p[M],col[N][N],a[N],x,y,z,ans,k;
string s;
int main() 
{
	scanf("%lld%lld",&k,&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll mx=0;
	for (int i=1;i<n;i++) mx=max(a[i+1]-a[i],mx);
	mx=max(mx,a[1]+k-a[n]);
	printf("%lld",k-mx);
}