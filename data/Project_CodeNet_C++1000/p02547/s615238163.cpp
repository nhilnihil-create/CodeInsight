#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
	// your code goes here
	int n,c=0;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(a==b)
		c++;
		else
		c=0;
		if(c==3)
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}