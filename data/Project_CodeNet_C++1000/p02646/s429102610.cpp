#include<bits/stdc++.h>
using namespace std;
int a,v,b,w,t;
int main()
{
	cin>>a>>v>>b>>w>>t;
	if(v<=w) return puts("NO"),0;
	int d=b-a;
	if(d<0) d=-d;
	if(1ll*(v-w)*t>=d) puts("YES");
	else puts("NO");
	return 0;
}