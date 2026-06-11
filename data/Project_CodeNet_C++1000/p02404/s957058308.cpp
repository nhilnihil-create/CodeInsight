#include<cmath>
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main() {
	int h, w;
	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0)break;
		for (int i = 0; i < w; i++)cout << "#"; cout << endl;
		for (int j = 0; j < h - 2; j++) {
			cout << "#";
			for (int k = 0; k < w - 2; k++)cout << ".";
			cout << "#" << endl;
		}
		for (int i = 0; i < w; i++)cout << "#"; cout << endl << endl;
	}
	return 0;
}