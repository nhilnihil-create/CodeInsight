#include<iostream>
using namespace std;
int main()
{
	int w,h,x,y,r,t=0;
	cin>>w>>h>>x>>y>>r;
	if(x>=r&&y>=r)
	{
		if((w-x)>=r&&(h-y)>=r)
		{
		t=1;}
	}
	if(t==1)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	
	return  0;
 } 
