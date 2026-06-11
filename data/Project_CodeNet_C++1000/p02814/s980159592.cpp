#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#include <numeric>
#include <queue>
#include <string.h>
#include <sstream>
#include <bitset>

#define ll long long int
#define ld long double
#define rep(i,n) for(ll i = 0;i < n;i++)
#define rep1(i,n) for(ll i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define allr(x) x.begin(),x.end(),greater<ll>()
#define P pair<ll,ll>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1ll << 60
#define PI 3.14159265359

using namespace std;

ll gcd(ll a, ll b) {
	if(a*b == 0) return max(a, b);
	if (a < b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}
	if (a%b == 0)return b;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main(){

	ll n,m;
	cin >> n >> m;

	vector<ll> a(n);

	for(ll i = 0;i < n;i++) {
		cin >> a[i];
		a[i] /= 2;
	}

	ll odd,even;
	ll even_count = 0;

	while(true){
		
		odd = 0;even = 0;

		for(ll i = 0;i < n;i++){
			if(a[i]%2 == 0) even++;
			else odd++;
		}

		if(even*odd != 0){
			cout << 0 << endl;
			return 0;
		}
		if(even == 0){
			break;
		}
		even_count++;

		for(ll i = 0;i < n;i++) a[i] /= 2;

	}

	ll lcm_all = lcm(pow(2,even_count),a[0]);

	for(ll i = 1;i < n;i++){
		lcm_all = lcm(lcm_all,a[i]);
		if(lcm_all > m) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << (m/lcm_all + 1)/2 << endl;

	return 0;
}
