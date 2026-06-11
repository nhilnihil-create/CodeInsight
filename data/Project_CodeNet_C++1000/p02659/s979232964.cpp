#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	ll a, ans = 0;
	double b, x;

	cin >> a >> b;

	x = 100*b+0.5;
	ans = (a*(ll)x)/100;
	cout << ans << endl;
	return 0;
}