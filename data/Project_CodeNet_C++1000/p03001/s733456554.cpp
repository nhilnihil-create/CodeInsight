#include "bits/stdc++.h"
using namespace std;

int main() {
	long long W , H,x,y;
	cin >> W>>H>>x>>y; 
	double s = W * H / 2.0;
	int t = 0;
	if (2*x ==W&&2*y==H) {
		t = 1;
	}
	printf("%.10f %d\n", s,t);
	return 0;
}
