#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,x,t;
int main()
{
	cin>>n>>x>>t;
	int count = 0;
	count = n / x;
	if(n % x != 0) count++;
	printf("%d\n",count * t);
	return 0;
}