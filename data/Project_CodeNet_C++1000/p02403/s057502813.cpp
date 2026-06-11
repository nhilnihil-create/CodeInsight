#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
	int h, w;
	for (int i = 0; i < 100000000; i++) {
		cin >> h >> w;
		if (h == 0 && w == 0) break;
		for (int j = 0; j < h; j++) {
			for (int t = 0; t < w; t++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
}
