#include <iostream>

using namespace std;

void tabuada(int valor) {
	for(int index = 1; index < 10; ++index)
		cout << valor << "x" << index << "=" << (valor * index) << endl;	
}

int main() {
	for(int index = 1; index < 10; ++index)
		tabuada(index);

	return 0;
}
