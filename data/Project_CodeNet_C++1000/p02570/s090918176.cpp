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
	double a, b, l, m, n;
	int x[10][10];
	int y[10];
	int i, j, k;
	bool flag = true;
	vector <long long int> e;
	cin >> n >> m >> l;
	a = n / l;
	if(a <= m)cout << "Yes" << endl;
		else cout << "No" << endl;
	return 0;
}