#include<bits/stdc++.h>
using namespace std;
long long ans,k;
queue<long long>q;
int main()
{
    cin>>k;
    for(long long i=1;i<=9;i++)
    {
    	q.push(i);
	}
	while(k--)
	{
		ans=q.front();
		q.pop();
		if(ans%10!=0) q.push(ans*10+ans%10-1);
		q.push(ans*10+ans%10);
		if(ans%10!=9) q.push(ans*10+ans%10+1);
	}
	cout<<ans;
	return 0;
}