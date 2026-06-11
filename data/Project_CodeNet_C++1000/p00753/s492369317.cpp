#include <cstdio>
#define MAX 246913

int main( void ){
	int n;
	int counter;
	int a[ MAX ] = {0};
	
	for( int i = 2; i <= MAX; i++ ){
		if( a[ i ] ){ continue; }
		for( int j = i * 2; j <= MAX; j += i ){
			a[ j ] = 1;
		}
	}
	
	while(1){
		scanf( "%d", &n ); 
		if(!n){break;}
		counter = 0;
		for( int i = n + 1; i <= 2 * n; i++ ){
			counter += (! a[ i ]);
		}
		printf( "%d\n", counter );
	}
	return 0;
}