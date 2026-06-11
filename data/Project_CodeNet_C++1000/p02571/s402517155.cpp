#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string S;
	string T;
	cin >> S;
	cin >> T;
	int lenS = S.size();
	int lenT = T.size();
	int max = 0;
	for (int i = 0; i < lenS - lenT + 1; i++) {
		int count = 0;
		for (int j = 0; j < lenT; j++) {
			if (S[i + j] == T[j]) {
				count++;
			}
			if (count > max) {
				max = count;
			}
		}
	}
	cout << lenT - max << endl;
	return 0;
}