#include<iostream>
#include<string>

using namespace std;

int main( )
{
	string cards, tmp;
	int m, h;
	
	while( cin>>cards ) {
		if( "-" == cards ) { break; }
	
		cin>>m;
		while( m-- ) {
			cin>>h;
			cards = cards.substr( h ) + cards.substr( 0, h );
		}
		cout<<cards<<endl;
	}
	
	return 0;
}