#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	long long int n,k,c=0;
 	cin>>n>>k;
 	while(n!=0)
 	{
 		n=n/k;
 		c++;
	 }
	 cout<<c<<endl;
 	return 0;
 }