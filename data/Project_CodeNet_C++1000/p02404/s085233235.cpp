#include<iostream>
using namespace std;

int main()
{
	int h, w;
	while (cin >> h >> w, !(w == 0 && h == 0)) {
		if (h == 1)cout << "#" << endl;
		else {

			for (int x = 0; x < w; x++) {
				cout << "#";
			}
			cout << endl;
			for (int y = 1; y < h - 1; y++) {
				cout << "#";
				for (int x = 1; x < w - 1; x++) {
					cout << ".";
				}
				cout << "#" << endl;
			}
			for (int x = 0; x < w; x++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}