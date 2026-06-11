#include <iostream>  
#include <stdlib.h>  
using namespace std;


int main() {
	int tate, yoko;
	while (true)
	{
		cin >> tate >> yoko;
		if (tate == 0 && yoko == 0)
			break;
		for (int i = 0; i < tate; i++){
			for (int j = 0; j < yoko; j++) 

				if (i != 0 && j != 0 && i != tate - 1 && j != yoko - 1)
					cout << ".";
				else
					cout << "#";
				cout << "\n";
			}
		cout << "\n";
	}
	

}