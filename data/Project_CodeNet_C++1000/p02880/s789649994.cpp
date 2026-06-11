#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,ok=0;
	cin>>a;
	for(int i=1;i<10;i++)
	{
		if((a%i)==0 && ((a/i)>=1 && (a/i)<=9))
		{
			ok=1;
			break;
		}
	}
	if(ok)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}