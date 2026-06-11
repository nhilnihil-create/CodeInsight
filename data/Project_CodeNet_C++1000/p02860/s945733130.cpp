#include<iostream>
using namespace std;

int main() {
	int N;
	string S;
	int i ,c ;
	cin >> N;
	cin >> S;
	c = 0;
	if (N % 2 != 0) {
		c = c + 1;
	}
	else {
		for (i = 0;i < N / 2; i++) {
			if (S[i] != S[N / 2 + i]) {
				c = c + 1;
			}
		}
	}
	
	if (c > 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
	
}