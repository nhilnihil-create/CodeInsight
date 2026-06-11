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
	int K, X;
	cin >> K >> X;
	int minX, maxX;
	minX = max(-1000000, X - (K - 1));
	maxX = min(1000000, X + (K - 1));
	for (int i = minX; i <= maxX; i++) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}