#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, d;
	string week[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
			"Saturday", "Sunday" };
	int day[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> m >> d) {
		if (m == 0)break;
		bool flag=false;
		int mc = 1;
		int cnt = 3;
		while (1) {
			for (int i = 1; i <= day[mc - 1]; ++i, cnt++) {
				if (mc == m && d == i) {
					cout << week[cnt % 7] << endl;
					flag=true;
					break;
				}
			}
			if(flag)break;
			mc++;
		}
	}
	return 0;
}