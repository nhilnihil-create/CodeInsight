/*
これを入れて実行
g++ code.cpp
./a.out
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy4[4] = { -1, 0, +1, 0 };
int dx4[4] = { 0, +1, 0, -1 };
int dy8[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
	return f.second > s.second;
}

ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

ll nCr(ll n, ll r){
	if (r == 0 || r == n){
		return 1;
	}
	else if (r == 1){
		return n;
	}
	return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}

ll nPr(ll n, ll r){
	r = n - r;
	ll ret = 1;
	for (ll i = n; i >= r + 1; i--) ret *= i;
	return ret;
}

//-----------------------ここから-----------

int main(void){
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> po;
	vector<ll> ne;

	vector<pair<ll, ll>> ans;

	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			ne.push_back(a[i]);
		}
		else {
			po.push_back(a[i]);
		}
	}

	sort(po.begin(), po.end());
	reverse(po.begin(), po.end());
	sort(ne.begin(), ne.end());

	if (ne.empty()){
		ne.push_back(po[po.size() - 1]);
		po.pop_back();
	}
	else if(po.empty()) {
		po.push_back(ne[ne.size() - 1]);
		ne.pop_back();
	}

	ll now = ne[0];

	for (int i = 0; i < po.size() - 1; i++){
		ans.push_back(make_pair(now, po[i]));
		now -= po[i];
	}

	ans.push_back(make_pair(po[po.size() - 1], now));
	now = po[po.size() - 1] - now;

	for (int i = 1; i < ne.size(); i++){
		ans.push_back(make_pair(now, ne[i]));
		now -= ne[i];
	}

	cout << now << endl;
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

