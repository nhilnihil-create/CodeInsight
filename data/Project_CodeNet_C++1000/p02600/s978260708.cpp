#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define MOD_Q 998244353
#define PI 3.14159265358979
#define ll long long
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x < 600) {
		printf("8");
	} else if (x < 800) {
		printf("7");
	} else if (x < 1000) {
		printf("6");
	} else if (x < 1200) {
		printf("5");
	} else if (x < 1400) {
		printf("4");
	} else if (x < 1600) {
		printf("3");
	}else if(x<1800){
		printf("2");
	} else {
		printf("1");
	}
	


	return 0;
}
