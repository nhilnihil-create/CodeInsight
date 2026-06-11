
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

int main(void){
//	FILE* fp_in = freopen("data.txt", "r", stdin);

	while( 1 ) {
		int n;
		cin >> n;
		if( n == 0 ) break;

		int ans = 0;
		bool ps = false;
		bool f[2] = {false,false};

		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if( s == "lu" )	f[0] = true;
			else if( s == "ru" ) f[1] = true;
			else if( s == "ld" ) f[0] = false;
			else if( s == "rd" ) f[1] = false;
			if( f[0] == false && f[1] == false ) {
				if( ps == true ) ans ++;
				ps = false;
			}
			if( f[1] == true && f[0] == true ) {
				if( ps == false ) ans ++;
				ps = true;
			}

			
		}
		cout << ans << endl;

	}

//	while(1){}
	return 0;
}