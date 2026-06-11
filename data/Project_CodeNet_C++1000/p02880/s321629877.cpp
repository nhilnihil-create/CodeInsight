#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=9;i++)
		if(n%i==0&&n/i<10)
			cout<<"Yes",exit(0);
	cout<<"No";	
	
}
