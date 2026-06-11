#include <bits/stdc++.h>
using namespace std;

int main(){
	int A1[3];
	int A2[3];
	int A3[3];
	cin >> A1[0] >> A1[1] >> A1[2];
	cin >> A2[0] >> A2[1] >> A2[2];
	cin >> A3[0] >> A3[1] >> A3[2];

	int N;
	cin >> N;

	int b[N];
	for (int loop = 0; loop < N; ++loop) {
		cin >> b[loop];
	}

	//A1行
	int flag = 0;
	for (int loop = 0; loop < 3; ++loop) {
		for (int loop1 = 0; loop1 <= N; ++loop1) {
			if (b[loop1] == A1[loop]) {
				++flag;
				if (3 == flag) {
					cout << "Yes" << endl;
					return 0;
				}
				break;
			}
		}
	}

	//A2列
	flag = 0;
	for (int loop = 0; loop < 3; ++loop) {
		for (int loop1 = 0; loop1 <= N; ++loop1) {
			if (b[loop1] == A2[loop]) {
				++flag;
				if (3 == flag) {
					cout << "Yes" << endl;
					return 0;
				}
				break;
			}
		}
	}

	//A3列
	flag = 0;
	for (int loop = 0; loop < 3; ++loop) {
		for (int loop1 = 0; loop1 <= N; ++loop1) {
			if (b[loop1] == A3[loop]) {
				++flag;
				if (3 == flag) {
					cout << "Yes" << endl;
					return 0;
				}
				break;
			}
		}
	}

	//A1[0],A2[0],A3[0]
	flag = 0;
	for (int loop1 = 0; loop1 <= N; ++loop1) {
		if (b[loop1] == A1[0]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A2[0]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A3[0]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	//A1[0],A2[1],A3[2]
	flag = 0;
	for (int loop1 = 0; loop1 <= N; ++loop1) {
		if (b[loop1] == A1[0]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A2[1]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A3[2]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	//A1[1],A2[1],A3[1]
	flag = 0;
	for (int loop1 = 0; loop1 <= N; ++loop1) {
		if (b[loop1] == A1[1]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A2[1]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A3[1]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	//A1[2],A2[2],A3[2]
	flag = 0;
	for (int loop1 = 0; loop1 <= N; ++loop1) {
		if (b[loop1] == A1[2]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A2[2]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A3[2]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	//A1[2],A2[1],A3[0]
	flag = 0;
	for (int loop1 = 0; loop1 <= N; ++loop1) {
		if (b[loop1] == A1[2]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A2[1]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (b[loop1] == A3[0]) {
			++flag;
			if (3 == flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
