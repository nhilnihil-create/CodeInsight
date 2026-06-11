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
int vis[1000005];
int a[200005];
int num[1000005];
int main()
{
	int n;sca(n);
	mem(num);
	for(int i=1;i<=n;i++)
	{
		sca(a[i]);
		num[a[i]]++;
	}
	sort(a+1,a+n+1);
	mem(vis);
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		continue;
		if(num[a[i]]>1)
		vis[a[i]]=1;
		for(int j=a[i]*2;j<=a[n];j+=a[i])
		vis[j]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]]==0)
		ans++;
	}
	
	printf("%d\n",ans);
}