#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a,b;
	double c;
	cin >> a >> b;
	cout << a/b << " " << a%b << " ";
	c = (double)a/b;
	printf("%8lf\n",c);
	return 0;
}