#include<cmath>
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main() {
	int h, w;
	int cnt = 0;
	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0)break;
		for (int i = 0; i < h; i++) {
			for (int j=0; j < w; j++) {
				if (cnt % 2 == 0)cout << "#";
				else cout << ".";
				cnt++;
			}
			cout << endl;
			
			if (w % 2 == 0)cnt++;
		}
		cnt = 0;
		cout << endl;
	}
	return 0;
}