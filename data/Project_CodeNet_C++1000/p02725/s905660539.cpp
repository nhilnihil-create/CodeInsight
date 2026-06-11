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

	int n, k;

	cin >> k >> n;

	vector<int> a(n + 1);

	rep(i, n) cin >> a[i + 1];

	a[0] = a[n] - k;

	vector<int> d(n);

	rep(i, n) {
		d[i] =k - (a[i + 1] - a[i]);
	}

	sort(d.begin(), d.end());

	cout << d[0] << endl;

	return 0;
}