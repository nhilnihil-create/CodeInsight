#include <iostream>  
#include <stdlib.h>  
using namespace std;


int main() {
	int tate, yoko;

	while (true) {
		cin >> tate >> yoko;
		if (tate == 0 && yoko == 0)
			break;
		for (int i = 0; i < tate; i++)
			for (int j = 1; j <= yoko; j++) {
				if (j < yoko)
					cout << "#";
				else
					cout << "#" << "\n";
			}
		cout << "\n";
	}
}