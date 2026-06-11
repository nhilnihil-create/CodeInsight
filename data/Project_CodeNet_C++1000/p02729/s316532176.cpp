#include <bits/stdc++.h>
using namespace std;
int main()
{
	int M,N,a,b,value;
	cin>>N>>M;
	--N;
	--M;
	a=(N*(N+1))/2;
	b=(M*(M+1))/2;
	value=a+b;
	cout<<value;
}