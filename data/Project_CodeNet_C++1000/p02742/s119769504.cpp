#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	long long h, w, a;
	cin >> h >> w;
	a = h*w;
	if (h != 1 && w != 1) {
		a = (h * w + 1) / 2;
		cout << a << endl;
	}
	else cout << 1 << endl;
	
}