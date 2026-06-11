#include<bits/stdc++.h>
using namespace std;
const int max_n=200005;
int a[max_n],b[max_n];
long long sum1[max_n],sum2[max_n];
long long max(long long a,long long b)
{
	return a>=b?a:b;
}
long long ans;
int main()
{
	int n;cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long num=n/i;
		ans+=(2*i+i*(num-1))*num/2;
	}
	cout<<ans;
}