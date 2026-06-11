#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll w,h,x,y;
	cin >> w >> h >> x >> y;
	double ans = 0;
	ans = max(ans,(double)h*min((double)x,(double)w-x));
	ans = max(ans,(double)w*min((double)y,(double)h-y));
	printf("%.15lf ",(double)h*w/2);
	if(w==x*2&&h==y*2)cout<<1<<endl;
	else cout<<0<<endl;
}