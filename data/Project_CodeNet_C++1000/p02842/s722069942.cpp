#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for(int X=1; X<=50000; X++){
		double w = X * 1.08;
		int n = (int)w;
		if(n == N){
			printf("%d\n", X);
			return 0;
		}
	}
	printf(":(\n");
	return 0;
}

