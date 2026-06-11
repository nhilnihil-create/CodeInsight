#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void countingOdd(vector <int> const& vect) {
	int count = 0;
	int result = 0;
	for (int i = 0; i < vect.size(); i++) {
		count++;
		if (count % 2 != 0 && vect[i] % 2 != 0) result++;
	}
	cout << result;
}
int main() {
	int numSquares; 
	cin >> numSquares;
	vector <int> squares(numSquares);
	for (int i = 0; i < numSquares; i++) {
		cin >> squares[i];
	}
	countingOdd(squares);
	return 0;
}