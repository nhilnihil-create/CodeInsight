#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	

	int a,b;
	
	cin >> a >> b;
	double g = a,j =b,f;
	
	/*a / b = d;
	a % b = r;
	*/

	f = g /j;
	
	
	printf("%d %d %.8lf\n",a / b, a % b, f);
	
return 0;
}