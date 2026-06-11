#include<iostream>
using namespace std;
int main() {
	int ki, co=0;
	while (1) {
		co = 0;
		cin >> ki;
		if (ki == 0) { break; }
		ki = 1000 - ki;
		if (ki >= 500) {
			ki = ki - 500;
			co++;
		}
		if (ki >= 100) {
			while(2){
				ki = ki - 100;
				co++;
				if (ki < 100) { break; }
			}
		}
		if (ki >= 50) {
			ki = ki - 50;
			co++;
		}
		if (ki >= 10) {
			while(2){
				ki = ki - 10;
				co++;
				if (ki < 10) { break; }
			}
		}
		if (ki >= 5) {
			ki = ki - 5;
			co++;
		}
		if (ki >= 1) {
			while(2){
				ki = ki - 1;
				co++;
				if (ki == 0) { break; }
			}
		}
		cout << co << endl;
	}
	return 0;
}