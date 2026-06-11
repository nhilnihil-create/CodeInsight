#include<iostream>
#include<stack>
#include<string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#define fast(); ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, n) for(int i= 0; i < n; ++i)
using namespace std;

int main() {
	int a, b, c, k; cin >> a >> b >> c >> k;
	if (k <= a) {
		cout << k << endl;
	}
	else if (k <= (a + b)) {
		cout << a << endl;
	}
	else {
		cout << a - (k - a - b) << endl;
	}
	return 0;
}
