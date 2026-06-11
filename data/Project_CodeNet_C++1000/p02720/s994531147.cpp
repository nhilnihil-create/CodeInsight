#include<bits/stdc++.h>
using namespace std;
deque<long long> a;
int main()
{
	int n,cn=9;
	cin>>n;
	if(n<10)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=9;i++)
		a.push_back(i);
	while(cn<n)
	{
		if(a.front()==0)
		{
			a.pop_front();
			cn--;
		}
		if(a.front()%10!=0)
		{
			a.push_back(a.front()*10+a.front()%10-1);
			cn++;
		}
		if(cn==n)break;
		a.push_back(a.front()*10+a.front()%10);
		cn++;
		if(cn==n)break;
		if(a.front()%10!=9)
		{
			a.push_back(a.front()*10+a.front()%10+1);
			cn++;
		}
		a.pop_front();
	}
	cout<<a.back();

	return 0;
}