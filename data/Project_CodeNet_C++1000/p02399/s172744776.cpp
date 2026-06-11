#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	int x=-1, y=-1,z=-1;
	double c=0;
	cin >> x >> y ;
	printf("%d %d %.5f\n", x / y, x%y, (double)x / y);
	return 0;
}