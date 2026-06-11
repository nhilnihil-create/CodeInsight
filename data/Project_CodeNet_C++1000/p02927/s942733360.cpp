#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,d;
	cin>>m>>d;
	int cnt=0;
	for(int i=20;i<=d;i++)
	{
		int x=i/10;
		int y=i%10;
		if((x*y)<=m&&x*y!=0&&y>=2)
		{
			//cout<<x*y<<endl;
			cnt++;
		} 
	}
	cout<<cnt<<endl;
}