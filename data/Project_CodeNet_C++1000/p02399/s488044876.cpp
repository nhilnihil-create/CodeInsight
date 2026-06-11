 #include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a , b ;
	double x , y ;
	cin >> a >> b ;
	x = a ;
	y = b ;
	cout << a / b <<" "<< a % b <<" ";
	printf("%.8lf\n", x / y );
}