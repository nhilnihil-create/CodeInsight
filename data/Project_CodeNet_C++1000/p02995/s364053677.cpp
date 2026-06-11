// Author : Harshdeep Sharma , IIT Indore
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #define MOD  998244353
#define ll long long
const double PI = atan(1.0) * 4;
// const ll INF = (int)1e9 ;
const int di[4] = { -1, 0, 1, 0} ;
const int dj[4] = {0, -1, 0, 1} ;
const ll INF = (ll)2e18 + 50;
const int maximum  = numeric_limits<int>::min();
const int minimum  = numeric_limits<int>::max();

// function to calculate any numbered power of some number without modulo
ll power(ll a , ll e) {
	ll res = 1LL ;
	while (e > 0) {
		if (e % 2 == 1) res = res * a;
		a =  a * a  ;
		e /= 2 ;
	}
	return res ;
}
// function to check whether a bracketed sequence is balanced or not
bool isBalanced(const string &exp) {
	// Initialising Variables
	bool flag = true;
	int count = 0;

	// Traversing the Expression
	for (int i = 0; i < exp.length(); i++) {

		if (exp[i] == '(') {
			count++;
		}
		else {
			count--;
		}
		if (count < 0) {
			flag = false;
			break;
		}
	}
	if (count != 0) {
		flag = false;
	}

	return flag;
}
// function to sort by second in a set of pairs
bool sortbysec(const pair<pair<int, int>, int> &a,
               const pair<pair<int, int>, int> &b) {
	return (a.second < b.second);
}

void uniformly_distribute_k_numbers_in_a_square_grid(int n , int k ) {
	int p = 0 , q = 0 ;
	vector<vector<int>> a(n, vector<int>(n)) ;
	for (int i = 1 ; i <= k ; ++i ) {
		a[p][q] = 1 ;
		p = p + 1 ;
		q = (q + 1) % n ;
		if (p == n) {
			p = 0  ;
			q = (q + 1) % n ;

		}
	}
}

// function to calculate gcd
ll gcd(int a, int b) {
	// Everything divides 0
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}


// main funtion
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t ;
	// cin >> t ;
	// while (t--) {

	ll a , b , c , d ;
	cin >> a >> b >> c >> d ;

	ll first_c , last_c , first_d , last_d ;
	first_c = a + c - (a % c) ;

	last_c  = b - b % c ;
	ll num_c = last_c - first_c + 1 ;
	first_d = a + d - (a % d) ;

	last_d  = b - b % d ;
	ll num_d = last_d - first_d + 1 ;

	ll l = c * d / gcd(c, d) ;
	ll first_l , last_l ;
	first_l = a + l - (a % l) ;
	last_l = b - (b % l) ;
	ll num_l = last_l - first_l + 1 ;
	// cout << b - a + 1 << " " << -last_l / l + first_l / l - 1 << " " ;
	ll tot = b - a + 1 ;
	ll c_part = last_c / c - first_c / c + 1 ;
	ll d_part = last_d / d - first_d / d + 1 ;
	ll l_part = last_l / l - first_l / l + 1 ;
	ll ans ;
	if (a % c != 0 && a % d != 0) ans =  tot - c_part  - d_part + l_part ;
	else if (a % c == 0 && a % d != 0) ans = tot - c_part - d_part + l_part - 1 ;
	else if (a % c != 0 && a % d == 0) ans = tot - c_part - d_part + l_part - 1 ;
	else ans =  tot - c_part  - d_part + l_part - 2 ;

	if (a % l != 0) cout << ans << "\n";
	else cout << ans + 1 << "\n";

	// cout << b - a + 1 - last_c / c + first_c / c - 1 - last_d / d + first_d / d - 1 + last_l / d - first_l / l + 1 << "\n";

	// cout << first_c << " " << last_c << "\n";








	// }







	return 0 ;
}
