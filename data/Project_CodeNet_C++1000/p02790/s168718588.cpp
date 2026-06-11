#include <iostream>
#include<cmath>
using namespace std;
int main(){
	int a, b, n = 0;
	cin >> a >> b;
	if (a < b)
		for (int i=0.0; i < b; i++)
			n += a*pow(10,i);
	else
		for (int i = 0.0; i < a; i++)
			n += b*pow(10,i);
	cout << n;
}