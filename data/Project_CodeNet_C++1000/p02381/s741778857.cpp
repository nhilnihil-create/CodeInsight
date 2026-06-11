#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

 int main(){
	 while( true ) {
		int studentNum = 0;
		cin >> studentNum;

		if ( studentNum == 0 ) {
			break;
		}

		vector<int> point(studentNum, 0);
		int sum = 0;
		for ( int i = 0; i < studentNum; i++ ) {
			cin >> point[i];
			sum += point[i];

		}

		// calculate average
		double average = (double)sum / (double)studentNum;
			
		// calculate variance
		double variance = 0;
		for( int i = 0; i < studentNum; i++ ) {
			double deviation	=	point[i]	- average;
			variance			+=	deviation	* deviation;

		}
		variance = variance / studentNum;
			
		// calculate standardDeviation
		double stdDeviation = sqrt(variance );

		printf( "%F\n", stdDeviation );

	 }
}