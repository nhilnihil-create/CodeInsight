#include <iostream>
#include <string>
using namespace std;
int main() {
	long long d=0;
	string x, y;
	cin >> x >> y;

	for (int i = 0; i <x.size() ; i++) {

		if (x[i] != y[i])
			d++;
	
	}
	
	cout << d;


}