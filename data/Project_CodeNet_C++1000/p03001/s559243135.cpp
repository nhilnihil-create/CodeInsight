#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int h,w,x,y;
	cin>>h>>w>>x>>y;
	cout<<(double)(h)*(double)(w)/2.0<<' '<<(x*2==h&&y*2==w? 1:0);
    return 0;
}
