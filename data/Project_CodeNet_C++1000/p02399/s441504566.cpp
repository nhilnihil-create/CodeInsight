  #include <iostream>
 #include <cstdio>
using namespace std;
	int main(){
		int a , b ;
		double x , y ;
		cin >> a >> b ;
		1 <= a , b <= 10*10*10*10*10*10*10*10*10;
		x = a ;
		y = b ;
		printf("%d %d %.8lf \n", a / b , a % b , x / y );
}