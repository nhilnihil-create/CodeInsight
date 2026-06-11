#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[6],b;
	for(int i=1;i<=5;i++)
	cin>>a[i];
	for(int i=1;i<=5;i++)
	if(a[i]==0)
	{
		b=i;
		break;
	}
	cout<<b<<endl;
	return 0;
}
