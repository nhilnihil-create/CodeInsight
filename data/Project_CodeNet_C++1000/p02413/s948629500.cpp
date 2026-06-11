#include<iostream>
using namespace std;


int main()
{
	int r, c;
	int m[101][101] = { { 0 } };
	cin >> r >> c;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> m[i][j];
		}
	}
	int allsum = 0;
	for (int i = 0; i < r; i++){
		int sum = 0;
		for (int j = 0; j < c; j++){
			cout << m[i][j] << " ";
			sum += m[i][j];
			allsum += m[i][j];
		}
		cout << sum << endl;
	}
	for (int j = 0; j < c; j++){
		int sum = 0;
		for (int i = 0; i < r; i++){
			sum += m[i][j];
		}
		cout << sum << " ";
	}
	cout << allsum << endl;
	
	return 0;
}