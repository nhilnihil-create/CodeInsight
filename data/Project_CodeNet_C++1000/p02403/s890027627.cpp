#include <iostream>
using namespace std;

int main()
{
	int h, w;
	while(true){
		cin >> h >> w;
		if(h == 0 && w == 0)
			break;
		for(int n = 1; n <= h; n++){
			for(int m = 1; m <= w; m++){
				cout << "#" ;
			}
			cout << endl;
		}
		cout << endl;
	}
}