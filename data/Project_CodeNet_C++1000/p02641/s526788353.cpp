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

int main()
{
	int x,n;sca(x);sca(n);
	int vis[105];
	mem(vis);
	for(int i=0;i<n;i++)
	{
		int y;sca(y);
		vis[y]=1;
	}
	int flag=0,minn=inf;
	for(int i=0;i<=101;i++)
	{
		if(vis[i]==0)
		{
			if(abs(i-x)<minn)
			{
				minn=abs(i-x);
				flag=i;
			}
		}
	}
	cout<<flag<<endl;
}