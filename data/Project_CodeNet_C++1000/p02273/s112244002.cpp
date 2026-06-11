#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<typename t1, class t2>
void input(t1 count,t2 array) {
	for(t1 i = 0;i < count;i++) {
		cin >> array[i];
	}
}

template<typename t1, class t2>
void output(t1 count,t2 array) {
	for(t1 i = 0;i < count;i++) {
		cout << array[i];
		if(i != count - 1) cout << " ";
	}
	cout << endl;
}

constexpr double rate = 1.0 / (2 * sqrt(3));

void dfs(double x1,double y1,double x2,double y2,int depth) {
	if(depth == 0) {
		cout << setprecision(10) << x1 << " " << y1 << endl;
	}
	else {
		double x[5],y[5];
		x[0] = x1; y[0] = y1;
		x[1] = (x1 * 2 + x2) / 3; y[1] = (y1 * 2 + y2) / 3;
		x[4] = x2; y[4] = y2;
		x[3] = (x2 * 2 + x1) / 3; y[3] = (y2 * 2 + y1) / 3;
		x[2] = (x1 + x2) / 2 + (y1 - y2) * rate;
		y[2] = (y1 + y2) / 2 + (x2 - x1) * rate;
		for(int i = 0;i < 4;i++) dfs(x[i],y[i],x[i+1],y[i+1],depth-1);
	}
}

int main(void) {
	int n;
	cin >> n;
	dfs(0,0,100,0,n);
	cout << setprecision(10) << "100.0 0.0" << endl;
}

