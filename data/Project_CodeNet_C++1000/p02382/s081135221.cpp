#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long ll;

string beautify(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if ('a' <= c && c <= 'z') ret += c;
		else if ('A' <= c && c <= 'Z') ret += (char)(c-'A'+'a');
	}
	return ret;
}

int main() {
	int n; cin >> n;
	int x[100], y[100];
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> y[i];

	for (int p = 1; p <= 3; ++p) {
		double d = 0;
		for (int i = 0; i < n; ++i) {
			d += pow( abs(x[i] - y[i]), p );
		}
		d = pow(d, 1.0/p);
		printf("%.10f\n", d);
	}
	{
		double d = 0;
		for (int i = 0; i < n; ++i) {
			d = max(d, (double)abs(x[i] - y[i]));
		}
		printf("%.10f\n", d);
	}
}