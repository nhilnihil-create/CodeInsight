#include <iostream>
using namespace std;
int main() {

	/* 177

	int D, T, S;
	cin >> D >> T >> S;
	int hour = D / S;
	if (D % S != 0)hour++;
	if (hour <= T) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
	
	*/

	/* 175
	string S;
	cin >> S;
	if (S == "RRR") {
		cout << 3 << endl;
	}
	else if (S == "SSS") {
		cout << 0 << endl;
	}
	else if (S == "SRR" || S == "RRS") {
		cout << 2 << endl;
	}
	else {
		cout << 1 << endl;
	}
	*/	

	/* 178
	int x;
	cin >> x  ;
	if (x == 1) {
		cout << 0 << endl;
	}
	if (x == 0) {
		cout << 1 << endl;
	}
	*/ 

	/* 174
	int X;
	cin >> X;
	if(X>=30){
		cout << "Yes"<<endl;
	}
	else{
		cout << "No"<<endl;
	}
	*/

	int N, X, T;
	cin >> N >> X >> T;
	if (N % X == 0) {
		cout << N / X * T << endl;
	}
	else {
		cout << N / X *T +T<<endl;
		return 0;


	}
}

