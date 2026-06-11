//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <math.h>
#include<algorithm>
#include <utility>
using namespace std;
int main() {//Thursda,Friday...0,1,2,3,4,5,6
	int month,day, today;//31%7=3
	int add=0;
	while (1) {
		cin >> month >> today;
		if (month == 0) {
			break;
		}
		if (month == 1) {
			add = 0;
		}
		else {
			for (int i = 1; i < month; i++) {
				if (i == 2) {
					add+=1;
				}
				else if ((i % 2 == 0 && i < 8) ||i==9|| i == 11 ) {
					add += 2;
				}
				else {//31??\
					add += 3;
				}
			}
		}
		today += add;
		day = today%7;
		switch (day) {
		case 1:cout << "Thursday" << endl; break;
		case 2:cout << "Friday" << endl; break;
		case 3:cout << "Saturday" << endl; break;
		case 4:cout << "Sunday" << endl; break;
		case 5:cout << "Monday" << endl; break;
		case 6:cout << "Tuesday" << endl; break;
		case 0:cout << "Wednesday" << endl; break;
		}
		add = 0;
	}
	return 0;
}