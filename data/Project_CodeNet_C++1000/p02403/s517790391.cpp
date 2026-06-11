#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const int M = 100000;
const double pi = 3.141592653589;

int main()
{
	int h, w;
	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}