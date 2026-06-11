#include <iostream>
#include <string>
using namespace std;
int main() {
	string x; int y,AC=0,WA=0,TLE=0,RE=0;
	cin >> y;
	for (int i = 0; i < y; i++){
		cin >> x;
		if (x == "AC") {
			AC++;
		}
		else if (x == "WA") {
			WA++;
		}
		else if (x == "TLE") {
			TLE++;
		}
		else if (x == "RE") {
			RE++;
		}
	}
	cout << "AC x " << AC << "\nWA x " << WA << "\nTLE x " << TLE << "\nRE x " << RE;
	return 0;
}