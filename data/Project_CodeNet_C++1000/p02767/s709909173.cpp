#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;


int main()
{
	int N;
	cin >> N;
	vector<int> Xn(N, 0);

	double sum = 0;
	rep(i, N) {
		cin >> Xn[i];
		sum += Xn[i];
	}
	int mean = round(sum / (double)N);

	sum = 0;
	rep(i, N){
		sum += (Xn[i] - mean) * (Xn[i] - mean);
	}

	cout << sum << endl;
	return 0;
} 