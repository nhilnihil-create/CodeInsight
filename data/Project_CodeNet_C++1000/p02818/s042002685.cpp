#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	ll A, B, K;
	cin >> A >> B >> K;
	if (A >= K) {
		A = A - K;
	}
	else if (A < K && K <= A + B){
		K = K - A;
		A = 0;
		B = B - K;

	}
	else {
		A = 0;
		B = 0;
	}
	cout << A << " " << B << endl;

	return 0;
}