#include <bits/stdc++.h>
using namespace std;

int n,pos;
int sumv[55];

struct node
{
	string title;
	int time;
}song[55];

int main()
{
	string s;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>song[i].title>>song[i].time;
		if (i==1)  sumv[i]=song[i].time;
		else sumv[i]=sumv[i-1]+song[i].time;
	} 
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		if (song[i].title==s)
		{
			pos=i;
			break;
		}
	}
	cout<<sumv[n]-sumv[pos]<<endl;
	return 0;
}