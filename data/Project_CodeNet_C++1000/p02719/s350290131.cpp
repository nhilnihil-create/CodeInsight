#include<iostream>
using namespace std;
int main()
{
        long long int n,k,factor;
        cin>>n>>k;
	if(k>n)
	{
		if(k-n<n)
			cout<<(k-n);
		else
			cout<<n;
	}
	else
	{
		factor=n/k;
		n=n-factor*k;
	        n=min(n,abs(n-k));
		cout<<n;
	}
}
