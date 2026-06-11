#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < N; j++) {
			if (S[i] == 'Z') S[i] = 'A';
			else S[i]++;
		}
	}
	cout << S << endl;
	return 0;
}