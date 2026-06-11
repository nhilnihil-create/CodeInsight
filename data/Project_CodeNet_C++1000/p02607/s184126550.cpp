#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,cnt=0;
	cin>>a;
	for (int i=0;i<a;i++)
	{
		cin>>b;
		if (b%2&&(i+1)%2)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
