#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iomanip>
#include <queue>

#define PI 3.14159265358979
#define MOD 1000000007

//fixed << setprecision(15) <<

using namespace std;

int main(void) {
	long long int  m, n;
	int i, j, k;
	cin >> n >> m;
	if (n % 2 == 1) {
		for (i = 0; i < m; i++) {
			cout << i + 1 << " " << n - i - 1 << endl;
		}
	}
	else if(n == 4){
		for (i = 0; i < m; i++) {
			cout << 2 << " " << 3 << endl;
		}
	}
	else {
		for (i = 0; i < m / 2; i++) {
			cout << i + 1 << " " << n / 2 - i << endl;
			cout << n / 2 + 1 + i << " " << n - 1 - i << endl;
		}
		if(m % 2 == 1)cout <<  1 + i << " " << n / 2 - i << endl;
	}
	return 0;
}