#include <iostream>
using namespace std;
int main()
{
	int A[3][3], N, b[10];
	int x = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	cin >> N;
	for (int k = 0; k < N; k++)
		cin >> b[k];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (b[k] == A[i][j])
					A[i][j] = 0;
	for (int i = 0; i < 3; i++)
		if (A[i][0] == 0 && A[i][1] == 0 && A[i][2] == 0)
			x += 1;
	for (int j = 0; j < 3; j++)
		if (A[0][j] == 0 && A[1][j] == 0 && A[2][j] == 0)
			x += 1;
	if (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) {
		x += 1;
	}
	if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) {
		x += 1;
	}
	if (x == 0)
		cout << "No" << "\n";
	else
		cout << "Yes" << "\n";
}