#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = -1; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;


int main() {

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	int cnt = 1;
	bool ans = false;

	while (a > 0 && b > 0) {
		if (cnt % 2 == 1) {
			c -= b;
		}
		else if (cnt % 2 == 0) {
			a -= d;
		}
		cnt++;
	}
	if (c <= 0) { ans = true; }

	puts(ans ? "Yes" : "No");

	return 0;
}