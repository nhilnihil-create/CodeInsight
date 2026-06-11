#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main(void){

	while( true ) {
		int n;
		cin >> n;
		if( !n ) break;
		n = 1000 - n;
		int ans = 0;
		int p[] = { 500, 100, 50, 10, 5, 1 };
	
		for( int i = 0; i < 6; i++ ) {
			ans += n / p[i];
			n %= p[i];
		}
		cout << ans << endl;
	}

    return 0;
}