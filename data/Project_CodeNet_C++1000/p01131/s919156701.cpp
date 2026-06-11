#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int a[1030];
	int k;
	stringstream sout;
	string b;
	int kari;
	int kaka;
	cin >> kaka;
	for  (int j = 0; j < kaka; j++) {
		cin >> b;
		kari = 0;
		int rireki[10] = {0};
		k = b.size();
		for (int i = 0; i < k; i++) {
			sout.str("");
			sout.clear();
			sout << b[i];
			sout >> a[i];
		}
		for (int i = 0; i < k-1; i++) {
			if(a[i] != a[i+1] && a[i+1] == 0 && a[i] != 0) {
				kari = 1;
				if (a[i] == 1) {
					if(rireki[1] % 5 == 0) {
						printf(".");
					} else if (rireki[1] % 5 == 1) {
						printf(",");
					} else if (rireki[1] % 5 == 2) {
						printf("!");
					} else if (rireki[1] % 5 == 3) {
						printf("?");
					} else {
						printf(" ");
					}
					rireki[1] = 0;
				} else if (a[i] == 2) {
					if(rireki[2] % 3 == 0) {
						printf("a");
					} else if (rireki[2] % 3 == 1) {
						printf("b");
					} else {
						printf("c");
					}
					rireki[2] = 0;
				} else if (a[i] == 3) {
					if (rireki[3] % 3 == 0) {
						printf("d");
					} else if (rireki[3] % 3 == 1) {
						printf("e");
					} else {
						printf("f");
					}
					rireki[3] = 0;
				} else if (a[i] == 4) {
					if (rireki[4] % 3 == 0) {
						printf("g");
					} else if (rireki[4] % 3 == 1) {
						printf("h");
					} else {
						printf("i");
					}
					rireki[4] = 0;
				} else if (a[i] == 5) {
					if (rireki[5] % 3 == 0) {
						printf("j");
					} else if (rireki[5] % 3 == 1) {
						printf("k");
					} else {
						printf("l");
					} 
					rireki[5] = 0;
				} else if (a[i] == 6) {
					if (rireki[6] % 3 == 0) {
						printf("m");
					} else if (rireki[6] % 3 == 1) {
						printf("n");
					} else {
						printf("o");
					}
					rireki[6] = 0;
				} else if (a[i] == 7) {
					if (rireki[7] % 4 == 0) {
						printf("p");
					} else if (rireki[7] % 4 == 1) {
						printf("q");
					} else if (rireki[7] % 4 == 2) {
						printf("r");
					} else {
						printf("s");
					}
					rireki[7] = 0;
				} else if (a[i] == 8) {
					if (rireki[8] % 3 == 0) {
						printf("t");
					} else if(rireki[8] % 3 == 1) {
						printf("u");
					} else {
						printf("v");
					}
					rireki[8] = 0;
				} else {
					if (rireki[9] % 4 == 0) {
						printf("w");
					} else if (rireki[9] % 4 == 1) {
						printf("x");
					} else if (rireki[9] % 4 == 2) {
						printf("y");
					} else {
						printf("z");
					}
					rireki[9] = 0;
				}
			} else {
				if (a[i] == 0 || (a[i] != a[i+1])) {
					rireki[a[i]] = 0;
					continue;
				}
				rireki[a[i]]++;
			}
		}
		if (kari == 1) {
			printf("\n");
		}
	}
	return 0;
}