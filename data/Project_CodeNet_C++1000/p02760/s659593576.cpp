#include<bits/stdc++.h>
using namespace std;

long long A[3][3];

int main(){
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}

	long long N;
	cin >> N;
	for(long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		for(int k = 0; k < 3; k++) {
			for(int j = 0; j < 3; j++) {
				if(A[k][j] == tmp) {
					A[k][j] = -1;
				}
			}
		}
	}

	for(int i = 0; i < 3; i++) {
		bool ok = true;
		for(int j = 0; j < 3; j++) {
			if(A[i][j] != -1) {
				ok = false;
			}
		}
		if(ok) {
			cout << "Yes" << endl;
		return 0;
		}
	}

	for(int i = 0; i < 3; i++) {
		bool ok = true;
		for(int j = 0; j < 3; j++) {
			if(A[j][i] != -1) {
				ok = false;
			}
		}
		if(ok) {
			cout << "Yes" << endl;
		return 0;
		}
	}

	if(A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) {
		cout << "Yes" << endl;
		return 0;
	}

	if(A[0][2] == -1 && A[1][1] == -1 && A[2][0] == -1) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;


}