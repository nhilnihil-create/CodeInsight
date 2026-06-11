#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>


#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

int main(void) {
	int a, b = 0;

	CI a >> b;

	//CO a / b << " " << a % b << " " << (double)a / (double)b E

	printf("%d %d %f",a / b,a % b,(double)a / (double)b);

}