#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
	// your code goes here
	long long n,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		sum+=(n-1)/i;
	}
	cout<<sum;
	return 0;
}