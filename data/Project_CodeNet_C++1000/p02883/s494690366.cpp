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

template<typename F> ll nibutan(ll ok, ll ng, F is_ok){
	if (ok - ng == 1) return ok;
	ll mid = (ok+ng)/2;
	if (is_ok(mid)) return nibutan(mid, ng, is_ok);
	return nibutan(ok, mid, is_ok);
}


int main(){
	ll sum = 0, maxa = 0, maxf = 0;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		maxa = llmax(a[i], maxa);
	} 
	for (int i = 0; i < n; i++){
		 cin >> f[i];
		 maxf = llmax(f[i], maxf);
	}

	if (sum - k <= 0){
		cout << 0 << endl;
		return 0;
	}

	sort(a.begin(), a.end());
	sort(f.begin(), f.end(), greater<ll>());

	cout << nibutan(maxa*maxf, 0, [&](ll x){
		ll sum = 0;
		for (int i = 0; i < n; i++){
			sum += llmax(a[i] - x/f[i], 0);
		}
		return sum <= k;
	}) << endl;

	return 0;
}

