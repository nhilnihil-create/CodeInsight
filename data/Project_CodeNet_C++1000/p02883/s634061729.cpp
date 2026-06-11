#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

ll n, k;

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

bool is_ok(ll x, vector<ll> &a, vector<ll> &f){
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += llmax(a[i] - x/f[i], 0);
	if (sum > k) return false;
	return true;
}

ll nibutan(ll ok, ll ng, vector<ll> &a, vector<ll> &f){
	if (ok - ng == 1) return ok;
	ll mid = (ok+ng)/2;
	if (is_ok(mid, a, f)) return nibutan(mid, ng, a, f);
	return nibutan(ok, mid, a, f);
}


int main(){
	ll sum = 0, maxa = 0, maxf = 0;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		maxa = max(a[i], maxa);
	} 
	for (int i = 0; i < n; i++){
		 cin >> f[i];
		 maxf = max(f[i], maxf);
	}

	if (sum - k <= 0){
		cout << 0 << endl;
		return 0;
	}

	sort(a.begin(), a.end());
	sort(f.begin(), f.end(), greater<ll>());

	cout << nibutan(maxa*maxf, 0, a, f) << endl;
	return 0;
}

