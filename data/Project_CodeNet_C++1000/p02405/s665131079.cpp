#include <iostream>
using namespace std;

int main() {
	int w, h;
	char a, b;

	while (true) {
		cin >> h >> w;
		if ( (h == 0)&&(w == 0)) break;
		b = '#';
		for (int i=0; i<h; i++) {
			a = b;
			for (int j=0; j<w; j++) {
				cout << a;
				a =  (a == '#') ? '.' : '#';
			}
			cout << "\n";
			b =  (b == '#') ? '.' : '#'; 
		}
		cout << "\n";
	}
	return 0;

}