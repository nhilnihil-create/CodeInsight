#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	int x, y, sum = 0;
	cin >> x;
	if (x == 1) {
		sum += 300000;
	} else if (x == 2) {
		sum += 200000;
	} else if (x == 3) {
		sum += 100000;
	}
	cin >> y;
	if (y == 1) {
		sum += 300000;
	} else if (y == 2) {
		sum += 200000;
	} else if (y == 3) {
		sum += 100000;
	}
	if(x==1&&y==1){
		sum+=400000;
	}
	cout << sum << endl;
	return 0;
}

