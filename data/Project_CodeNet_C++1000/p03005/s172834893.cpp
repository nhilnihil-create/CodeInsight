#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main() {

	int n, k;
	scanf("%d%d",&n,&k);
	if(k == 1){
	  printf("0\n");
	}else{
	  n -= k;
	  printf("%d\n",n);
	}
	return 0;
}
