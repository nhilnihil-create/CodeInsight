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

unsigned gcd(unsigned a, unsigned b) {
	if (a < b) return gcd(b, a);

	unsigned c;

	while ((c = a % b)) {
		a = b;
		b = c;
	}
	return b;
}

ll lcm(ll a, ll b) {
	ll c = gcd(a, b);
	return a / c * b;
}


int main() {

	int s, w;

	cin >> s >> w;

	bool ans= true;

	if (s <= w) ans = false;

	puts(ans ? "safe" : "unsafe");


	return 0;
}