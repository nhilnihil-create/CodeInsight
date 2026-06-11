#include <iostream>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
	int num[3];
	cin >> num[0];
	cin >> num[1];
	cin >> num[2];

	sort( num, num + 3 );

	for ( int i = 0; i < 3; i++ ) {
		if ( i < 2 ) {
			cout << num[i] << " ";

		} else if ( i == 2 )
			cout << num[i] << endl;
		}
}