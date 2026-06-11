#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
	double w,h;
	cin>>w>>h;
	double x,y;
	cin>>x>>y;
	double ans=(w*h)/2;
	cout<<ans<<" ";
	if(w/2==x && h/2==y)
		cout<<"1";
	else
		cout<<"0";
    return 0;
}