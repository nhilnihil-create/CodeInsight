#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	long long  a, b;
	cin >> a >> b;
	cout << a/b << ' ' << a%b << ' ';
	printf("%f.6\n",(double)a/double(b));

	return 0;
}