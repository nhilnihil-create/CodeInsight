#include<iostream>


using namespace std;

int main() {
	int H;
	int W;
	int N;
	cin >> H;
	cin >> W;
	cin >> N;

	int paintCount = 0;
	int paintBlack = 0;
	while (1) {

		if (H > W) {
			paintBlack = paintBlack + H;
			paintCount++;
		}
		else {
			paintBlack = paintBlack + W;
			paintCount++;
		}

		if (N <= paintBlack) {
			break;
		}
	}

	cout << paintCount << endl;

}
