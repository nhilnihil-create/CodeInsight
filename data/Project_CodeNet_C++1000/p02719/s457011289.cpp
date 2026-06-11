#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k;
	cin>>n>>k;
	if(n<k)
	{
		cout<<min(n,abs(n-k))<<endl;
	}
	else
	{
		if(n%k==0)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<(((n/k)+1)*k)-n<<endl;
		}
	}
	
}