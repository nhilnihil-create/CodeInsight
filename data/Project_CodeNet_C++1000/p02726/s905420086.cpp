#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=11000,M=1001001;
ll n,m,T,cnt,f[N][N],p[M],col[N][N],ans[N],x,y,z,k;
string s;
int main() 
{
	scanf("%lld%lld%lld",&n,&x,&y);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			ll mi=(j-i);
			mi=min(mi,1+abs(i-x)+abs(j-y));
			mi=min(mi,1+abs(i-y)+abs(j-x));
			ans[mi]++;
		}
	for (int i=1;i<n;i++) printf("%lld\n",ans[i]);
}