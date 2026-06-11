#include <iostream>
using namespace std;
	int main(){
		int W , H , x , y , r;
		cin >> W >> H >> x >> y >> r;
		-100 <= x , y <= 100;
		0 < W , H , r <= 100;
		if ( x + r <= W && x - r >= 0 && y + r <= H && y - r >= 0 )
	     cout << "Yes" << endl;
	     else 
	    	   cout << "No" << endl;
	}