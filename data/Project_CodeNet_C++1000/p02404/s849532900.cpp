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
				if(n ==1 || n == h){
					cout << "#" ;
				}
				else if(m ==1 || m == w){
					cout << "#";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}