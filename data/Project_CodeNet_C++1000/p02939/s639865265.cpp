#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;


int main() {
	string S, X = "", Y ="";
	cin >> S;
	int count = 0;

	for (int i = 0; i < S.size(); i++) {
		X += S[i];
		if (X != Y) {
			count++;
			Y = X;
			X = "";
			
		}
	}
	

	cout << count;

	return 0;
}
