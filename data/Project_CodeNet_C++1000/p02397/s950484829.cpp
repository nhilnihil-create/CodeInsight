#include <iostream>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
	while ( true ) {
		int x, y;
		cin >> x;
		cin >> y;

		if ( x == 0 && y == 0 ) {
			break;
		}

		int small, large;

		if ( x < y ) {
			small = x;
			large = y;
		
		} else {
			small = y;
			large = x;
		}

		cout << small << " " << large << endl;

	}
}