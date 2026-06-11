#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


int main(){

	
	double ax, ay, bx, by;

	cin >> ax >> ay >> bx >> by;

	double distance = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

	printf("%.7lf\n", distance);
	

	//system("pause");
    return 0;
}


