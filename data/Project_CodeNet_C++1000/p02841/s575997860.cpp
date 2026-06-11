#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int M1, D1, M2, D2;
	cin >> M1 >> D1;
	cin >> M2 >> D2;

	if(M1 != M2 && D2 == 1){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
	return 0;
}