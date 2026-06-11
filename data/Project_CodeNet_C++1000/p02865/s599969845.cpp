#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt;
	cin>>n;
	if(n%2==1)
		for(int i=1;i<=n/2;i++)
		{
			cnt++;
		} 
	else 
		for(int i=1;i<n/2;i++)
		{
			cnt++;
		} 
	cout<<cnt;
	return 0;
}
