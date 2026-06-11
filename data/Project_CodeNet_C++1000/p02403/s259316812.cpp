#include<iostream>
using namespace std; //or std::cin et al.

int main() {
	int w,h;
	
	while (1) {
	    cin >> h >> w;
		if ( w == 0 && h == 0 ) {
			break;
		}
		for ( int i = 0; i < h; i++ ) {
	            for ( int j = 0; j < w; j++ ) {
	    	        cout << "#";
	            }
	            cout << "\n";
                }
            cout << endl;
	}
	return 0;
}
