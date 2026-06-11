#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int v,w,t;
	int a,b;
	cin>>a>>v;
	cin>>b>>w>>t;
	int dist=abs(a-b);
	int rel=v-w;
	if(rel<0){puts("NO");}
	else
	{
		int cover=rel*t;
		if(cover<dist)
		{puts("NO");}
		else puts("YES");
		
		
	}
	
}