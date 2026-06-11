#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	string S, T;
	cin >> S;
	T = S;
	reverse(T.begin(), T.end());
	int n = (int)S.size() / 2; 
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] != T[i]) count++;
	}
	cout << count << endl;
	return 0;
}