#include <iostream>
using namespace std;
int main(void) {


	double dist, time, speed;
	cin >> dist >> time >> speed;
	if ((dist / speed) <= time) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}


	return 0;
}