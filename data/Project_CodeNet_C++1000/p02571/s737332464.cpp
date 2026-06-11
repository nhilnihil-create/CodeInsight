#include<iostream>
using namespace std;

int main() {

	//S > T
	string S;
	string T;

	do {

		cin >> S;
		cin >> T;


	} while (S.length() - T.length() < 0 && S.length() >=1000 && T.length() >= 1000);

	int min_num = 10001;
	for (int i = 0; i < S.length() - T.length()+1; i++) {


		int count_num = 0;

		for (int j = 0; j < T.length(); j++) {
			

			if (S[i + j] != T[j]) {
				count_num++;
			}

		}

		if (count_num < min_num) {
			min_num = count_num;
		}


	}

	cout << min_num;


	return 0;
}