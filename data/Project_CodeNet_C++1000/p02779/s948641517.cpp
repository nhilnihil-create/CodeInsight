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
	int n;
	cin >> n;
	map<ll, ll> mp;
	rep(i, n) {
		ll drn; cin >> drn;
		mp[drn]++;
		if (mp[drn] != 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
