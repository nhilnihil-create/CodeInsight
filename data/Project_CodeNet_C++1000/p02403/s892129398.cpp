#include <iostream>
#include <string>

using namespace std;

void DrawRect(int h, int w) {
	for( int i=0; i<h; i++ ) {
		string s = "";
		for( int j=0; j<w; j++ ) {
			s += "#";
		}
		cout << s << endl;
	}
}

int main() {
	int h,w;
	while( true ) {
		cin >> h >> w;
		if( h == 0 && w == 0 ) break;
		DrawRect( h, w );
		cout << endl;
	}
	return 0;
}