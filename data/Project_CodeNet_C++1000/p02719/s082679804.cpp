#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k,rem,ans;
	cin>>n>>k;
	rem=n%k;
	if(rem==0)
	{
		cout<<"0";
		return 0;
	}
	else
	{
		if(rem>k/2)
		rem=k-rem;
		cout<<rem;	
	}
}