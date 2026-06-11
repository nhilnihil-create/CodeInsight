#include <iostream>
using namespace std;

int main(void){

	int kousya[4][3][10], n, b, f, r, v;
	cin >> n;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 10; k++){
				kousya[i][j][k] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cin >> b >> f >> r >> v;
		kousya[b-1][f-1][r-1] += v;
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 10; k++){
				cout << " " <<  kousya[i][j][k];
			}
			cout << endl;
		}
		if (i == 3) break;
		cout << "####################" << endl;
	}

	return 0;
}