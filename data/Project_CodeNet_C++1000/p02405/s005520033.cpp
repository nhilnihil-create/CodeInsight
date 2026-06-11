#include <iostream>
using namespace std;

int main()
{

	int H, W;

	while( cin >> H >> W, H || W ) {

		for( int i = 1; i <= H; i++ ) {
			for( int j = 1; j <= W; j++ ) {

				if( !( i % 2 ) && !( j % 2 ) ) cout << "#";
				else if( !( i % 2 ) && ( j % 2 ) ) cout << ".";

				if( ( i % 2 ) && !( j % 2 ) ) cout << ".";
				else if( ( i % 2 ) && ( j % 2 ) ) cout << "#";

			}
			cout << endl;
		}

		cout << endl;

	}

	return 0;

}