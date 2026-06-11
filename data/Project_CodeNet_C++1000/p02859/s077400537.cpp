#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int main () {
	int r; 
	cin >> r;
	int area = M_PI * (r * r);
	cout << ceil(area / M_PI);
	return 0;
}