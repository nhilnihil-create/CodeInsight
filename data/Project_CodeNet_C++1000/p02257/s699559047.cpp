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

#define MAX 10000001

static bool gosei[MAX];

void a() {
	for (int i = 2; i <= sqrt(MAX); i++)
		if (gosei[i] == false) {
			for (int j = 2, k = 0; (k = i*j) <= MAX; j++)
				gosei[k] = true;
		}
}

int c(int a) {
	if (a % 2 == 0)return 0;
	for (int i = 3; i <= sqrt(a); i += 2)
		if (a%i == 0)
			return 0;
	return 1;
}

int main() {
	a();
	int b = 0;
	for (int a; cin >> a;) {
		if (a < MAX) {
			if (!gosei[a])b++;
		}
		else
			b += c(a);
	}
	cout << b << endl;
	return 0;
}