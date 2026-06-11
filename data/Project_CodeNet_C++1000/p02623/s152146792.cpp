#include<bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
#define sca(x) scanf("%d",&x)
#define scall(x) scanf("%lld",&x)
#define eps 1e-6
ll a[200005],b[200005];
ll suma[200005],sumb[200005];
int main()
{
	int n,m,k;sca(n);sca(m);sca(k);
	suma[0]=0;sumb[0]=0;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		scall(a[i]);
		suma[i]=suma[i-1]+a[i];
		if(suma[i]<=k)
		maxn=max(maxn,i);
	}
	
	int na=n;
	for(int i=1;i<=m;i++)
	{
		scall(b[i]);
		sumb[i]=sumb[i-1]+b[i];
		if(sumb[i]<=k)
		maxn=max(maxn,i);
		while(sumb[i]+suma[na]>k)
		na--;
		maxn=max(maxn,na+i);
	}
	cout<<maxn<<endl;
}