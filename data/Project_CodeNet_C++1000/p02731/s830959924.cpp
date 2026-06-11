#include <iostream>

using namespace std;

int main() {
	int L;
	do {
		cin>>L;
	} while (L < 1 || L > 1000);
	double L_double = static_cast<double>(L);
	double max_x, max_y, max_z;
	max_x = L_double / 3;
	max_y = max_x;
	max_z = max_x;

	double volumen{max_x*max_y*max_z};
	cout <<fixed<< volumen;
	return 0;
}