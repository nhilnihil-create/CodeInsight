#include<iostream>
#include<queue>
#include<memory>
#include<map>
#include<set>
#include<unordered_map>
#include<array>
#include<vector>
#include<algorithm>
#include<list>
#include<limits>
#include<stdio.h>
#include<math.h>
#include<string>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;
using pr  = pair<ll, ll>;

const ll MOD = 998244353;

int main()
{
	int N;
	cin >> N;

	map<ll, ll> mp;

	ll ans = 0;

	for (ll i = 0; i < N; ++i)
	{
		ll A; cin >> A;

		ans += mp[i - A];

		mp[i + A]++;
	}

	cout << ans << endl;

	return 0;
}