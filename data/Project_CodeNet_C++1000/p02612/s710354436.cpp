#include <iostream>
using namespace std;
int main() {
	int N,x;
	cin >> N;
	if ( N%1000 == 0) {
		cout << 0 << endl;
	}
	else {
		x = N / 1000;
		x++;
		cout<<1000*x-N <<endl;
	}
	
	return 0;
}