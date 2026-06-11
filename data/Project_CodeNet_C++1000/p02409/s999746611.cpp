#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>


#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;


int main(void) {
	int num = 0;
	int b = 0, f = 0, r = 0, v = 0;
	int situation[4][3][10] = {0};

	CI num;

	for (int i = 0; i < num; ++i) {
		CI b >> f >> r >> v;
		situation[b - 1][f - 1][r - 1] += v;
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 10; ++k) {
				CO  " " << situation[i][j][k];
			}
			CO  endl;
		}
		if (i == 3)break;
		CO "####################" E
	}
}