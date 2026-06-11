#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;
 
#define PI 3.14159265358979323846264338327950L

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int cnt = 1;
	while ( 1 ) {
		if (cnt % 2 == 1) {
			C -= B;
			if (C <= 0) {
				cout << "Yes" << endl;
				return 0;
			}
		} else {
			A -= D;
			if (A <= 0) {
				cout << "No" << endl;
				return 0;
			}
		}
		cnt++;
	}
}