#include <iostream>
using namespace std;
 
int main() {
	int X; cin >> X;
	if (X >= 2000) cout << "1" << endl;
	else if ((X / 100) * 5 < X % 100) cout << "0" << endl;
	else cout << "1" << endl;
	return 0;
}