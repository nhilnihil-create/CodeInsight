#include <iostream>
using namespace std;
int main(){
		int W,H,x,y,r;
		cin >> W >> H >> x >> y >> r;
		bool j = true;
		if(x-r<0) j = false;
		if(x+r>W) j = false;
		if(y-r<0) j = false;
		if(y+r>H) j = false;
		if(j) cout << "Yes" << endl;
		else  cout << "No"  << endl;
		return 0;
}