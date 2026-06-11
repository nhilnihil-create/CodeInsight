#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main()
{
	int n;
	cin>>n;
	queue<ll> q;

	for(int i=1;i<=9;i++)
	{
		q.push(i);
	}

	ll ans;

	while(!q.empty())
	{
		ll num=q.front();
		q.pop();
		n--;
		if(n==0)
		{
			ans=num;
			break;
		}

		ll rem=num%10;

		if(rem==0)
		{
			q.push(10*num);
			q.push(10*num+1);
		}
		else if(rem==9)
		{
			q.push(10*num+8);
			q.push(10*num+9);
		}

		else
		{
			q.push(10*num+rem-1);
			q.push(10*num+rem);
			q.push(10*num+rem+1);
		}

	}

	cout<<ans<<endl;

	return 0;
}