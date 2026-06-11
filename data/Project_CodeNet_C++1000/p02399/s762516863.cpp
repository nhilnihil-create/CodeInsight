#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	double a,b;
	cin>>a>>b;
	cout<<(int)a/(int)b<<endl;
	cout<<(int)a%(int)b<<endl;
	printf("%.6lf\n",a/b);
	return 0;
}