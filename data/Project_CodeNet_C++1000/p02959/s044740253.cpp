#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;


int main()
{
	int n;
	cin >> n;
	vector<int> aa(n + 1);
	vector<int> bb(n);
	rep(i, n + 1) cin >> aa[i];
	rep(i, n) cin >> bb[i];
	ll sum = 0;
	rep(i, n + 1) sum += aa[i];
	ll sa = 0;
	rep(i, n) {
		if (aa[i] >= bb[i]) {
			aa[i] -= bb[i];
			bb[i] = 0;
		}
		else {
			bb[i] -= aa[i];
			aa[i] = 0;
		}
		if (aa[i+1] >= bb[i]) {
			aa[i+1] -= bb[i];
		}
		else {
			aa[i+1] = 0;
		}
		sa += aa[i];
	}
	sa += aa[n];
	ll ans = sum - sa;
	cout << ans;
}