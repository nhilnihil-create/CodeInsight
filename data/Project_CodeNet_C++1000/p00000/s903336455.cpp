#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b;

	for (a=1; a<=9; a++){
		for (b=1; b<=9; b++){
			cout << a << 'x' << b << '=' << a * b << '\n';
		}
	}

	return 0;
}