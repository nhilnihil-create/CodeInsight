#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char buf[10];

int main(){

	scanf("%s",buf);

	switch(buf[0]){
	case 'S':

		printf("Cloudy\n");
		break;

	case 'C':

		printf("Rainy\n");
		break;

	case 'R':

		printf("Sunny\n");
		break;
	}

	return 0;
}
