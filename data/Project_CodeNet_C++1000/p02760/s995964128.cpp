#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int N;
	
	vector<vector<int>> A(3, vector<int>(3));
	vector<vector<int>> C(3, vector<int>(3,0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A.at(i).at(j);
			C.at(i).at(j) = 0;
		}
	}

	cin >> N;

	vector<int> b(N);
	for (int i = 0; i < N; i++)cin >> b.at(i);


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < N; k++) {
				if (A.at(i).at(j) == b.at(k))C.at(i).at(j) = 1;
				
			}
		}
	}
	if (C.at(0).at(0) == 1 && C.at(0).at(1) == 1 && C.at(0).at(2) == 1)cout << "Yes" << endl;
	else if (C.at(1).at(0) == 1 && C.at(1).at(1) == 1 && C.at(1).at(2) == 1)cout << "Yes" << endl;
	else if (C.at(2).at(0) == 1 && C.at(2).at(1) == 1 && C.at(2).at(2) == 1)cout << "Yes" << endl;
	else if (C.at(0).at(0) == 1 && C.at(1).at(1) == 1 && C.at(2).at(2) == 1)cout << "Yes" << endl;
	else if (C.at(0).at(2) == 1 && C.at(1).at(1) == 1 && C.at(2).at(0) == 1)cout << "Yes" << endl;
	else if (C.at(0).at(0) == 1 && C.at(1).at(0) == 1 && C.at(2).at(0) == 1)cout << "Yes" << endl;
	else if (C.at(0).at(1) == 1 && C.at(1).at(1) == 1 && C.at(2).at(1) == 1)cout << "Yes" << endl;
	else if (C.at(0).at(2) == 1 && C.at(1).at(2) == 1 && C.at(2).at(2) == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}