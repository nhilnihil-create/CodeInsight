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

int f(const vector<int> &a) {
	int res ;
	int n = a.size() ;
	vector<int> cnt(n + 1) ;
	for (int i = 0 ; i < n ; i++) {
		++cnt[a[i]] ;
	}
	for (int i = 0 ; i < n ; i++) {
		if (cnt[i] == 0) {
			res = i ;
			break ;
		}
	}
	return res ;
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
	// 	int n ;
	// 	cin >> n ;
	// 	vector<int> a(n) ;
	// 	vector<int> cnt(n + 1);
	// 	vector<int> res ;
	// 	int temp_prev , temp_new ;
	// 	for (int i = 0 ; i < n ; i++) {
	// 		cin >> a[i] ;
	// 		++cnt[a[i]] ;
	// 	}


	// if (f(a) == n) {
	// 	temp_prev = f(a) ;
	// 	for (int i = 0 ; i < n ; i++) {

	// 		while (a[i] != i) {
	// 			res.push_back(i) ;
	// 			res.push_back(a[i]) ;
	// 			res.push_back(i) ;
	// 			// res.push_back(i) ;
	// 			// swap(a[i] , a[a[i]]) ;
	// 			temp_new = a[a[i]] ;
	// 			a[a[i]] = a[i]  ;
	// 			// a[i] = temp_prev ;
	// 			temp_prev = temp_new ;
	// 			a[i] = temp_prev ;

	// 			// break ;
	// 		}
	// 		for (auto i : a) {
	// 			cout << i << " " ;
	// 		}
	// 		cout << "\n";
	// 		// cout << f(a) << "\n";
	// 	}


	// }
	// for (auto i : a) {
	// 	cout << i << " " ;
	// }
	string s ;
	cin >> s ;
	int n = s.length() ;
	set<char> s1 ;
    s1.clear() ; 
	for (int i = 0 ; i < n ; i++) {
		s1.insert(s[i]) ;
	}
	if (s1.size() == 2) cout << "Yes\n";
	else cout << "No\n";
















	// }







	return 0 ;
}
