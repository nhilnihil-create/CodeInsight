#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>


#define CI cin >>
#define CO cout <<
#define E << endl;
#define F(i,max) (for(int i = 0;i < max;++i))

using namespace std;


int main(void) {
	int m[10000];
	int f[10000];
	int r[10000];

	char result[10000];

	for (int i = 0; i < 10000; i++) {
		CI m[i];
		CI f[i];
		CI r[i];
		if (m[i] == -1 && f[i] == -1 && r[i] == -1) {
			break;
		}

		if (m[i] == -1 || f[i] == -1) {
			result[i] = 'F';
		}
		else {
			if ((m[i] + f[i]) >= 80) {
				result[i] = 'A';
			}

			if (65 <= (m[i] + f[i]) && (m[i] + f[i]) < 80) {
				result[i] = 'B';
			}

			if (50 <= (m[i] + f[i]) && (m[i] + f[i]) < 65) {
				result[i] = 'C';
			}

			if ((30 <= (m[i] + f[i]) && (m[i] + f[i]) < 50) && r[i] < 50) {
				result[i] = 'D';
			}

			if ((30 <= (m[i] + f[i]) && (m[i] + f[i]) < 50) && r[i] >= 50) {
				result[i] = 'C';
			}

			if ((m[i] + f[i]) < 30) {
				result[i] = 'F';
			}
		}

		CO result[i] E
	}
}