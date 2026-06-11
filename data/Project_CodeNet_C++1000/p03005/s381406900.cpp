#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <tuple>
#include <utility>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define RSORT(x) sort(x.begin(),x.end(),greater<int>())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define setp(x) setprecision(x)
using LL = long long;
using ULL = unsigned long long;

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << n - k << endl;
	}

	return 0;
}
