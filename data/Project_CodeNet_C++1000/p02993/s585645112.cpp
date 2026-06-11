#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char buf[5];

int main(){

	scanf("%s",buf);

	if(buf[0] == buf[1] || buf[1] == buf[2] || buf[2] == buf[3]){

		printf("Bad\n");

	}else{

		printf("Good\n");
	}

	return 0;
}
