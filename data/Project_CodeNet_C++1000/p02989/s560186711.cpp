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

const ll MA = 1000005;


int main() {

	vector<int> to(MA);

	int n;
	ll sum = 0;
	cin >> n;
	vector<int> d(n);

	rep(i, n) cin >> d[i];

	sort(d.begin(), d.end());

	int a = d[(n - 1) / 2], b = d[((n - 1) / 2) + 1];

	bool f = false;

	if (a != b) {
		f = true;
	}
	if (f) {
		cout << b - a << endl;
	}
	else cout << "0" << endl;

	return 0;
}