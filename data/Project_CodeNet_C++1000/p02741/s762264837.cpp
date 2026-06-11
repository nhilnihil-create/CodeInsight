#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

static int C[33] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int K;
	cin >> K;
	printf("%d\n", C[K-1]);
	return 0;
}