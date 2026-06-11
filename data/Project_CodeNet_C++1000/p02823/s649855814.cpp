#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,b;
	cin>>n>>a>>b;

	if(abs(a-b)%2==0)
	{
		cout<<(abs(a-b))/2<<endl;
	}
	else
	{
		long long a1 = min(a-1,b-1);

		long long a2 = max(a-1,b-1);
		long long d1 = a1 + 1 + (a2-a1-1)/2;

		a1 = min(n-a,n-b);
		a2 = max(n-a,n-b);

		long long d2 = a1 + 1 + (a2-a1-1)/2;

		cout<<min(d1,d2)<<endl;
	}

	
	return 0;
}