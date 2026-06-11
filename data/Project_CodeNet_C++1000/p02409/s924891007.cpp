#include<iostream>
using namespace std;



int main(){
	int A[3][10];
	int B[3][10];
	int C[3][10];
	int D[3][10];
	for (int j = 0; j < 10; j++){
		for (int i = 0; i < 3; i++){
			A[i][j] = 0;
			B[i][j] = 0;
			C[i][j] = 0;
			D[i][j] = 0;
		}
	}

	int n;
	int b, f, r, v;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> b >> f >> r >> v;
		switch (b)
		{
		case 1:
			A[f - 1][r - 1] += v;
			break;
		case 2:
			B[f - 1][r - 1] += v;
			break;
		case 3:
			C[f - 1][r - 1] += v;
			break;
		case 4:
			D[f - 1][r - 1] += v;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			cout << " " << A[i][j];
		}
		cout << endl;
	}
	for (int k = 0; k < 20; k++){
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			cout << " " << B[i][j];
		}
		cout << endl;
	}
	for (int k = 0; k < 20; k++){
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			cout << " " << C[i][j];
		}
		cout << endl;
	}
	for (int k = 0; k < 20; k++){
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			cout << " " << D[i][j];
		}
		cout << endl;
	}
	return 0;
}