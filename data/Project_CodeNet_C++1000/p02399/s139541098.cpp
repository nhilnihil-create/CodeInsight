#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	
	long int a;
	long int b;
	cin >> a >> b;
	cout << a / b << endl;
	cout << a%b << endl;
	printf("%.8lf",(double)a/(double)b);

	return 0;
}