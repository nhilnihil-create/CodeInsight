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
ll Max = 10 + 1e8;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	sort(h.begin(), h.end(),greater<ll>());
	ll sum = 0;
	for (int i = k;i < n;i++) {
		sum += h[i];
	}
	cout << sum;
}