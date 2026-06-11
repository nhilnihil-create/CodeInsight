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

ll choose(ll i)
{
	return i*(i - 1) / 2;
}
int main()
{
	
	int n; cin >> n;
	vector<string> ss(n);
	map<string, ll> mp;
	rep(i, n) {
		cin >> ss[i];
		sort(ss[i].begin(), ss[i].end());
		mp[ss[i]]++;
	}
	ll cnt = 0;
	rep(i, n) {
		cnt += choose(mp[ss[i]]);
		mp[ss[i]] = 1;
	}
	cout << cnt;
}