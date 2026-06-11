#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{  
    double a,b,c,d;
	cin>>a>>b>>c>>d;

	double e=(a-c)*(a-c)+(b-d)*(b-d);
	e=sqrt(e);
	
	//cout<<e<<endl;
	printf("%.5f",e);
	cout<<endl;
    
	return 0;
}
