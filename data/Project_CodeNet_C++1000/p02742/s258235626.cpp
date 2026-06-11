#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int h,w,a,b;
	cin>>h>>w;
	if(w==1 || h==1)
	{
		cout<<1<<endl;	
		return 0;
	}
	
	else if(w%2==0)
	{
		a=h*(w/2);
	}
	else
	{
		if(h%2==0)
		{
			a=(h*w)/2;
		}
		else
		{
			b=((w-1)/2)+1;
			a=b+(((h-1)/2)*w);
		}
	}
	cout<<a<<endl;
}