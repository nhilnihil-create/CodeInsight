#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main() {
	int n,i,j,pin=0,p=0;
	while (1) {
		cin >> n;
		if (n == 0) { break; }
		for (i = n+1; i < 2 * n + 1; i++) {
			for (j = 2; j <sqrt((double) i)+1; j++) {
				if (i%j == 0) {
					pin = 1;
					break;
				}
			}
			if (pin == 0) { p = p + 1; }
			else { pin = 0; }
		}if (n == 1) { cout << 1<<endl; }else{cout << p << endl;
	}
		p = 0;
	}
	return 0;
}