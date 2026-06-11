#include <iostream>
#include <cmath>
using namespace std;
const int Day = 24, Sxd = 60; // Sexagesimal number

int main() {
	int S, hour, min, sec;
	cin >> S;

	if(S >= 0 && S < Day*(Sxd*Sxd) ) {
		hour = S/(Sxd*Sxd);
		min = (S-hour*(Sxd*Sxd)) / Sxd;
		sec = (S-hour*(Sxd*Sxd)) - (min*Sxd);

		cout << hour << ":" << min << ":" << sec << endl;
	}
	return 0;
}