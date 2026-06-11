#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string.h>
#include <deque>
#define REP(i,j,n) for(int i=j;i<n;i++)
#define SORT(x) sort(x.begin(),x.end())

using namespace std;

int main() {
	float n, sum = 0, avr,bunsan1=0 ,bunsan2;

	for (;;) {
		cin >> n;
		vector<int> v(n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		avr = sum / n;

		for (int i = 0; i < n; i++) {
			bunsan1 += (avr - v[i])*(avr - v[i]);
		}
		bunsan2 = bunsan1 / n;

		printf("%f\n", sqrt(bunsan2));
		sum = 0; bunsan1 = 0;
	}
	return 0;
}