/**
 *    author:  Baibhav Kumar
 *    created: 24.07.2020 19:00:00      
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
 	long long rs = 100 , step = 0;
	while (rs < n) {
		rs += rs / 100;
		step++;
	}
	cout << step << endl;
}
