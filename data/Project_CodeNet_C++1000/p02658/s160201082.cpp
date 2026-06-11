#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int n;
int main() {
	cin >> n;
	vector<ll> a(n); rep(i, 0, n) cin >> a[i];


	double alog = 0;
	rep(i, 0, n){
		// 0が含まれているか
		if(a[i] == 0){
			cout << "0" << endl;
			return 0;
		}

		// 配列全部の積の桁数を求める
		alog += log10(a[i]);
	}

	// 1e18 を大きく超えているか
	if(alog > 18){
		cout << "-1" << endl;
		return 0;
	}

	// 積を求める
	ll ans = 1;
	rep(i, 0, n){
		ans *= a[i];
		if(ans > 1000000000000000000){
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << ans << endl;
    return 0;
}
