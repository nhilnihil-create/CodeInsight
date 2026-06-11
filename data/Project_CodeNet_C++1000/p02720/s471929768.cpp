#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int k;
	cin>>k;
	queue<ll>q;
	for(int i=1; i<10; i++)
	 q.push(i);
	ll num;
	while(k--)
	{
		num=q.front();
		q.pop();
		int rem=num%10;
		if(rem!=0)
		 q.push(10*num+rem-1);
		q.push(10*num+rem);
	    if(rem!=9)
	     q.push(10*num+rem+1);
	}
	cout<<num;
	return 0;
}