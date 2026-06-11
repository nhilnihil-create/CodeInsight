#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	double a[1001] , total =0 ;
	while(1){
		total=0;
	cin >> n ;
	if( n==0 ) break;
	for( int i=0 ; i<n ; i++ ){
		cin >> a[i] ;
		total += a[i] ;
	}
	double average = total/(double)n;
	total = 0;
	for( int i=0 ; i<n ; i++){
		total += pow((a[i] - average ) , 2 );
	}
	total = total/n;
	cout << sqrt( total ) << endl;
}
}