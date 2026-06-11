#include<bits/stdc++.h>
using namespace std;
#define lld long double
int main()
{
	lld x,y,w,h;
	cin>>w>>h>>x>>y;
	if(x==w/2&&y==h/2)
	{
		cout<<(w*h)/2<<" 1\n";
	}
	else if(x==w/2)
	{
		cout<<(w*h)/2<<" 0\n";

	}
	else if(y==h/2)
	{
		cout<<(w*h)/2<<" 0\n";

	}
	else
	{
		cout<<(w*h)/2<<" 0\n";
	}

}