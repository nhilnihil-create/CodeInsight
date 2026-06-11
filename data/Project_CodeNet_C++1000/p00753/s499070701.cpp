
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

//nが素数かどうかを判定する関数
int isPrime(int n) {
	if(n == 0) return 0;
	if(n == 1) return 0;

	int flg = 1;
	for(int i = 2; i < (int)sqrt((double)n) + 1; i++) {
		if( n % i == 0 ) {
			flg = 0;
			break;
		}
	}
	return flg;
}

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);

	while(1) {
		int n, ans = 0;
		cin >> n;
		if( n == 0 ) break;
		for(int i = n + 1 ; i <= 2 * n; i ++) 
			if(isPrime(i)) ans ++;

		cout << ans << endl;
	}

	
	//while(1){}
	return 0;
}