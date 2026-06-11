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
	int input[100000][2] = {};
	int memo = 0;

	for (int i = 0; i < 100000; ++i) {
		CI input[i][0];
		CI input[i][1];
		if (input[i][0] == 0) {
			memo = i;
			break;
		}
	}

	for (int i = 0; i < memo; ++i) {
		for (int k = 0; k < input[i][0]; ++k) {
			for (int j = 0; j < input[i][1]; ++j) {
				CO "#";
			}
			CO "\n";
		}
		CO "\n";
	}
}