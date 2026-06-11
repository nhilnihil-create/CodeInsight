#include <iostream>
#include<math.h>
using namespace std;

int main(){
	int N; cin >> N;

	double tmp = N / 1.08;
	int roundUp = (int)ceil(tmp);
	int roundDown = (int)floor(tmp);

	double roundUpX = roundUp * 1.08;
	double roundDownX = roundDown * 1.08;

	if (N == (int)floor(roundUpX)) {
		cout << roundUp;
	}
	else if (N == (int)floor(roundDownX)) {
		cout << roundDown;
	}
	else {
		cout << ":(";
	}
}