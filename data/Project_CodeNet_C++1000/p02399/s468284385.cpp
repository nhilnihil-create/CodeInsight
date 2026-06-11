#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int a, b;
int main(){
	cin >> a >> b;

	cout << (a / b) << " " << (a%b) << " ";
	printf("%f05\n", (a / (double)b));

	return 0;
}