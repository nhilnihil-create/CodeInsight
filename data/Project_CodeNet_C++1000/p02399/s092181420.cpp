#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << a / b << " ";
	cout << a % b << " ";
	printf("%.5lf\n", 1.0 * a / b);
    return 0;
}