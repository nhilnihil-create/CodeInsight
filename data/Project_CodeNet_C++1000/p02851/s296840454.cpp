#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, K; cin >> N >> K;
	ll tot = 0, ans = 0;
	map<ll, int> mp;
	mp[0]++;
	queue<ll> qu;
	qu.push(0);
	for (ll i = 1; i <= N; i++) {
		if (i >= K) {
			mp[qu.front()]--;
			qu.pop();
		}
		ll a; cin >> a; tot += a;
		ll temp = (tot - i) % K;
		//printf("i=%d temp=%lld mp[%lld]=%d\n", i, temp, temp, mp[temp]);
		ans += mp[temp];
		mp[temp]++;
		qu.push(temp);	
		
	}
	
	cout << ans << endl;
}


