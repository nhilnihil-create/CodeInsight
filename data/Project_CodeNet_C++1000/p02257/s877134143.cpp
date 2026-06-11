#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

int c(int a) {
	if (a == 2)return 1;
	if (a % 2 == 0)return 0;
	for (int i = 3; i <= sqrt(a); i += 2)
		if (a%i == 0)
			return 0;
	return 1;
}

int main() {
	int b = 0;
	for (int a; cin >> a;)
		b += c(a);
	cout << b << endl;
	return 0;
}