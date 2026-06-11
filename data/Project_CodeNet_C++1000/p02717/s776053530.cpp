#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,t;
	cin>>a>>b>>c;
	t=a;
	a=b;
	b=t;
	t=a;
	a=c;
	c=t;
	cout<<a<<" "<<b<<" "<<c;
}