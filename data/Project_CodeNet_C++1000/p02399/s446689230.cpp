#include<iostream>
#include<cstdio>
#include<cstdint>
using namespace std;

int main(){

	int32_t a, b;

	cin >> a >> b;

	printf("%d %d %.5f\n", a / b, a % b, (double)a / b);

	return 0;
}