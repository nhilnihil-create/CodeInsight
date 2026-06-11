#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define eps 1.0e-14;

ll combination(ll n,ll r){
	ll a = 1,b = 1;
	for (int i = n; i > n - r; i--){
		a *= i;
	}
	for (int i = r; i > 0; i--){
		b *= i;
	}
	return (a / b);
}

ll nc2(ll x){
	return (((x) * (x - 1)) / 2);
}

int main(){
	int a,b; cin >> a >> b;
	int ans = 0;
	if (a - (b * 2) < 0) ans = 0;
	else ans = a - (b * 2);
	cout << ans << endl;
	return 0;
}
