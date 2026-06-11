#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int x,y,z,n,f=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>y;
		
		if(y%2==0)
		{
			if( y%3!=0 && y%5!=0) f=1; 		
		}
		
	}
	if(f==0) cout<<"APPROVED";
	else cout<<"DENIED";
	return 0;
}