#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int D,T,S;
	cin >> D >> T >> S;
	if ((D + T - 1) / T <= S) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	

	return 0;
}