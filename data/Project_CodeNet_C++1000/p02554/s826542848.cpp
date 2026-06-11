#include<bits/stdc++.h>
using namespace std;
long long mod(long long a, long long n, long long x)
{
	long long y=a%x ,odd=1;
	while(n/2)
	{
		if(n&1)
			odd=(odd*y)%x;
		y=(y*y)%x;
		n/=2;
	}
	odd=(odd*y)%x;
	return odd;
}
int main()
{
	long long n;
	cin >> n;
	//cout << mod(22, 4, 4) << "\n";
	long long M=1000000007;
	long long all=mod(10, n, M);
	long long only9_0=mod(9, n, M);
	long long both=mod(8, n, M);
	//cout << all << "\n" << only9_0 << "\n" << both << "\n";
	all=(all- only9_0 + M)%M;
	all=(all- only9_0 + M)%M;
	cout << (all + both)%M;
	return 0;
}