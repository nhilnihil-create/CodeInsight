#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	int N;
	cin >> N;

	for(int i=1; i<=9; i++){
		int q = N / i;
		int r = N % i;
		if(r == 0 && q >= 1 && q <= 9){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}