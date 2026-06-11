/*
luogu AT4900
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,ans;
struct vec{
	int x,y;
}a[205];

bool cmp(vec a,vec b)
{
	if(atan2(a.y,a.x)==atan2(b.y,b.x))
		return a.x<b.x;
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;cin>>a[i].x>>a[i].y,i++);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		a[n+i] = a[i];
	for(int l=1;l<=n;l++)
	{
		int x=0,y=0;
		for(int r=l;r<l+n;r++)
		{
			x += a[r].x, y += a[r].y;
			ans = max(ans,x*x+y*y);
		}
	}
	printf("%.11lf\n",sqrt(ans));
	
	return 0;
}