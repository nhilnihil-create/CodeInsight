#include <bits/stdc++.h>
using namespace std;
long long a,b,k;
int main() 
{
	cin>>a>>b>>k;
	long long takahashi,aoki;
	if(k<=a) 
	{
		takahashi=a-k;
		aoki=b;
	}
	else 
		if(k<=a+b)
		{
			takahashi = 0;
			aoki=b-(k-a);
		}
		else
		{
			takahashi=0;
			aoki=0;
		}
	cout<<takahashi<<" "<<aoki;
}