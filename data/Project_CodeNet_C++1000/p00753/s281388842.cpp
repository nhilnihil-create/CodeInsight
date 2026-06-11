#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <vector>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <time.h>
#define all(c) ((c).begin(),(c).end())
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n)
#define vsort(v) sort(v.begin(),v.end())
#define vvsort(v) sort(v.begin(),v.end(),greater<int>())
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
//---------------------------------------------------------------------------------------------//
int n;
bool isso(int a) {
	int i = 2;
	while (i*i <= a) {
		if (a%i == 0)return 1;
		i++;
	}
	return 0;
}

int main() {
	while (cin >> n, n) {
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (!isso(i)) {
				ans++;
			}
		}
		cout << ans << endl;
	}

}