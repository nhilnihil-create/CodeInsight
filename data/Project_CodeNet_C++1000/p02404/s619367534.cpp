#include<iostream>
using namespace std;
int main() {

	int H, W;
	cin >> H >> W;

	while (H != 0){

		int j, k;
		for (j = 0; j < H; j++){
			for (k = 0; k < W; k++){

				if (j == 0 || j == H - 1 || k == 0 || k == W - 1)
					cout << "#";
				else cout << ".";

			}
			cout << endl;
		}
		cout << endl;
		cin >> H >> W;
	}
	return 0;
}
