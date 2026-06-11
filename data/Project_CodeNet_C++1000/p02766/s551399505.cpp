#include <cstdio>
#include <math.h>
using namespace std;

void findNumOfDigit(long n,int base){
	
		int dig = (int)(floor( log(n)/log(base))+1);
		
		printf("%d",dig);
	}

int main(){
	long n;int base;
	scanf("%ld %d",&n,&base);
	findNumOfDigit(n,base);
	return 0;
	}
