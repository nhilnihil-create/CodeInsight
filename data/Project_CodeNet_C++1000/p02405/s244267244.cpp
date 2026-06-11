#include<iostream>
using namespace std;
int main() {
	int h, w,a,b;
	for (;;) {
		cin >> h >> w;
		if (h < 1 && w < 1) {
			return 0;
		}
		a = h;
		b = w;
		for (; h > 0;h=h-1) {
			if ((a - h) % 2 == 0) {
				for(;w>0;w=w-1){
					if ((b - w) % 2 == 0) {
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
				w = b;
				cout << endl;
			}
			else {
				for (; w > 0; w = w - 1) {
					if ((b - w) % 2 == 0) {
						cout << "." ;
					}
					else {
						cout << "#" ;
					}
				}
				w = b;
				cout << endl;
			}
		}
		h = a;
		cout << endl;
	}
}
