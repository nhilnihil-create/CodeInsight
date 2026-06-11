#include<iostream>

using namespace std;

int main()
{

	int H,W;
	bool pattern=true;
	
	while( true ) {
		cin>>H>>W;	
		if( 0==H && 0==W ) { break; }
		for( int i=0; i<H; i++ ) {
			pattern = (0==i%2)? true: false;
			for( int j=0; j<W; j++ ) {
				if( pattern ) {
					cout <<"#"; 
					pattern=!pattern;
				} else {
					cout <<"."; 
					pattern=!pattern;
				}
			}
			cout <<endl;  
		}
		cout <<endl; 
	}
	
    return 0;
}