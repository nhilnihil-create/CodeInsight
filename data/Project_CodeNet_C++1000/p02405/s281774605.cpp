#include <iostream>
using namespace std;

void out(int d, int w)
{
	switch(d%2) {
	case 0:
		for ( int i = 0; i < w ; i++) {
			switch(i%2) {
			case 0:
				cout << '#';
				break;
			case 1:
				cout << '.';
			}
		}
		break;
	case 1:
		for ( int i = 0; i < w ; i++) {
			switch(i%2) {
			case 0:
				cout << '.';
				break;
			case 1:
				cout << '#';
			}
		}
	}		
}

int main()
{
	int h, w;
	
	cin >> h >> w;
	
	while ((h!=0)&&(w!=0)) {
		for (int i=0; i < h; i++) {
			out(i,w);
			cout << endl;
		}
		cout << endl;
		cin >> h >> w;
	}
	return 0;
}