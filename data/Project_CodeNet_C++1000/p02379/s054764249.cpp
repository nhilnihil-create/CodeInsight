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
	double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	double dx = x2 - x1, dy = y2 - y1;
	printf("%.10f\n", sqrt(dx*dx + dy*dy));
}