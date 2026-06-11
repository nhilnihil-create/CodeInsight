#include<stdio.h>
#include<cmath>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<queue>
#include<set>
#include<utility>
#include<climits>
#include<iomanip>
#include<limits>
#include<thread>
#include<map>
#include<stack>
#include<numeric>
#include<cstring>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<tuple>
#include <cstdio>
using namespace std;

#define pb          push_back
#define mp          make_pair
#define ll          long long int
#define hmap        unordered_map
#define pii         pair<int,int>
#define pdd         pair<double, double>
#define M           1000000007
#define MOD         998244353
#define fast        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test        ll t; cin>>t; while(t--)
#define inp(a,n)    int a[n]; for(int i=0;i<n;i++)  cin>>a[i];
#define inpl(a,n)   ll a[n];  for(ll i=0;i<n;i++)   cin>>a[i];
#define out(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define outl(a,n)   for(ll i=0;i<n;i++)  cout<<a[i]<<" "; cout<<endl;
#define outv(v)     for(int i=0;i<v.size();i++) cout<<v[i]<<" ";  cout<<endl;
#define all(s)      (s).begin(),(s).end()

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n+1; i++)
#define repr(i,n) for(int i=n-1; i>=0; i--)
#define repr1(i,n) for(int i=n; i>0; i--)
#define FOR(i,j,n) for(int i=j; i < n; i++)
#define souatari(i,j,n) rep1(i,n-1)rep(j,i)
#define souatari1(i,j,n) for(int i=2; i<n+1; i++)rep1(j,i-1)
#define mp make_pair
#define F first
#define S second
#define elif else if
#define inpv(a,n)   vector<ll>a(n);  for(ll i=0;i<n;i++)   cin>>a[i];

// class Solution {
// public:
// 	set<string>ans ;
// 	void permute_helper(string ss, string dum, vector<string>&per) {
// 		if (ss.size() == 0) {
// 			per.push_back(dum) ;
// 		}
// 		else {
// 			// choose
// 			for (int i = 0 ; i < ss.size(); i++) {
// 				// choose
// 				char dd = ss[i] ;
// 				dum.push_back(ss[i]);
// 				ss.erase(ss.begin() + i) ;
// 				//explore
// 				permute_helper(ss, dum, per);
// 				//unchoose
// 				dum.pop_back();
// 				ss.insert(ss.begin() + i, dd) ;
// 			}
// 		}
// 	}
// 	void permute(string ss, vector<string>&per) {
// 		permute_helper(ss, {}, per) ;
// 	}
// 	void sublist_helper(string tiles, string store) {
// 		if (tiles.empty()) {
// 			if (store == "") return ;
// 			// base case
// 			vector<string>per ;
// 			permute(store, per);
// 			for (int i = 0 ; i < per.size(); i++) {
// 				if (per[i] == "") continue ;
// 				if (ans.count(per[i]))  continue ;
// 				else ans.insert(per[i]) ;
// 			}

// 		}
// 		else {
// 			// remove
// 			// choose
// 			char temp = tiles.back() ;
// 			tiles.pop_back() ;
// 			// explore
// 			sublist_helper(tiles, store);
// 			store.push_back(temp);
// 			sublist_helper(tiles, store) ;
// 			// unchoose
// 			tiles.push_back(temp) ;
// 			store.pop_back();
// 		}


// 	}
// 	void sublist(string tiles) {
// 		string dum = "" ;
// 		sublist_helper(tiles, dum) ;
// 	}
// 	int numTilePossibilities(string tiles) {
// 		sublist(tiles);
// 		// reverse(tiles.begin(),tiles.end());
// 		// sublist(tiles);
// 		return ans.size() ;
// 	}
// };

// ll  efficient_expo(ll a , ll  b , ll mod) {
// 	ll res = 1 ;
// 	// a = a % mod;
// 	// b = b % mod ;
// 	while (b > 0) {
// 		if (b & 1) res = (res * a) % mod ;
// 		a = (a * a) % mod ;
// 		b = b >> 1 ;
// 	}
// 	return res ;
// }

// int modd(int a, int b, int c)
// {
// 	if (b == 0) return 1;

// 	if (b % 2 == 0)
// 	{
// 		int x = modd(a, b / 2, c);
// 		return (x * x) % c;
// 	}
// 	else return (a % c * modd(a, b - 1, c)) % c;
// }

// ll recursive_mod(ll a , ll b , ll mod) {
// 	if (b == 0) return 1 ;
// 	if (b & 1) return (a % mod * recursive_mod(a, b - 1, mod)) % mod;
// 	ll x = (recursive_mod(a, b / 2, mod)) ;
// 	return ((x ) * (x )) % mod ;
// }

// ll leading_digit(ll a , ll b , ll k) {
// 	long long double  pro = b * log10(a) ;
// 	long long double deci = pro - floor(pro) ;
// 	int po = pow(10, k - 1);
// 	return (ll)(((long long double)pow(10, deci)) * po) ;
// }

// bool check(int num, set<int>ff) {
// 	while (num) {
// 		int a = num % 10 ;
// 		if (ff.count(a)) return false;
// 		num = num / 10 ;
// 	}
// 	return true ;
// }

// int findm(vector<int>arr, int n) {

// 	// Calculating MAX in array
// 	int high = 0;
// 	for (int i = 0; i < n; i++)
// 		high = max(high, arr[i]);

// 	// Maintaining count array
// 	int count[high + 1] = {0};
// 	for (int i = 0; i < n; i++)
// 		count[arr[i]]++;


// 	int counter = 0;


// 	for (int i = high; i >= 1; i--)
// 	{
// 		int j = i;
// 		counter = 0;


// 		while (j <= high)
// 		{


// 		if (count[j] >= 2)
// 				return j;

// 			else if (count[j] == 1)
// 				counter++;


// 			j += i;


// 			if (counter == 2)
// 				return i;
// 		}
// 	}
// // 	return -1 ;
// // }

// void fib(vector<ll>&dp) {
// 	dp[0] = 0 ; dp[1] = 1 ;
// 	for (int i = 2; i <= 70; -i++) {


// 		dp[i] = dp[i - 1] + dp[i - 2] ;
// 	}
// 	//cout << dp[100k] << endl ;
// }
// // int divisorSum(int n)
// // {tutcu()
// // 	int sum = 0;c()
// // 	for (int i = 1; i <= n; ++i)
// // 	tur	sum = (n / i) * i;
// // 	return sum;
// // }
// {
// 	cout << "index is -> " << index << " stored_values -> "  ;
// 	for (int i = 0 ; i < store.size(); i++) {
// 		cout << store[i] << " " ;
// 	}
// 	cout << endl ;
// }



ll divisorSum(ll n) {
	ll ans = 0 ;
	for (int i = 1; i <= n; ++i) {
		ll sum = 0;
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				if (i / j == j)
					sum += 1;
				else
					sum += 2;
			}
		}
		//cout << ans << " " ;
		ans = ans + sum * i ;
	}
	return ans;
}



double myPow(double x, long long n) {
	if (x == 1) return 1 ;
	if (n < 0) { x = 1 / x  ; n = -n ;}
	double ans = 1 ; double yo = x ;
	while (n) {
		if (n & 1) ans = ans * yo ;
		yo = yo * yo ;
		n = n >> 1 ;
	}
	return ans ;
}

// set<ll>gogo;
// ll recurse(ll N) {
// 	if (gogo.count(N)) return -1 ;
// 	gogo.insert(N) ;
// 	if (N == 1) return 0 ;
// 	ll p = 1 + recurse(2 * N) ;
// 	ll pp = INT_MAX - 1000;
// 	if (N % 6 == 0) pp = 1 + recurse(N / 6) ;
// 	return min(p, pp) ;
// }
// int soo = 0;

// void dice_helper(int dice, int target, vector<int>store, int mini, int sum) {
// 	soo++ ;
// 	if (dice == 0) {
// 		// base case
// 		if (sum == target) {
// 			for (int i : store) {
// 				cout << i << " " ;
// 			}
// 			cout << endl ;

// 		}
// 	}
// 	//choose
// 	else  {
// 		for (int  i = mini; i <= 6; i++) {
// 			if (sum + i > target) continue ;
// 			store.push_back(i);
// 			dice_helper(dice - 1, target, store, i, sum + i);
// 			store.pop_back();
// 		}
// 	}

// }

// void dice_main(int dice , int sum) {
// 	vector<int>yo ;
// 	int min_val = 1 ;
// 	dice_helper(dice, sum, yo, min_val, 0);
// }




// set<string>ans ;
// int counti ;
// void sublist_helper(string tiles, string store, int cc) {
// 	if (cc == counti) {
// 		// base case
// 		if (ans.count(store)) return ;
// 		ans.insert(store) ;
// 	}
// 	else {
// 		cc = cc + 1 ;
// 		char temp = tiles.back() ;
// 		tiles.pop_back() ;
// 		// explore
// 		sublist_helper(tiles, store, cc);
// 		store.push_back(temp);
// 		sublist_helper(tiles, store, cc) ;
// 		// unchoose
// 		tiles.push_back(temp) ;
// 		store.pop_back();
// 	}
// 	// remove
// 	// choose


// }
// void sublist(string tiles) {
// 	string dum = "" ;
// 	sublist_helper(tiles, dum, 0) ;
// }
// int numTilePossibilities(string tiles) {
// 	sublist(tiles);
// 	// reverse(tiles.begin(),tiles.end());
// 	// sublist(tiles);
// 	return ans.size() ;
// }

// ll fact(ll a , ll b) {
// 	a = a % 10 ;
// 	b = b % 10 ;
// 	ll diff = a - b ;
// 	ll ans = a ;
// 	while (diff) {
// 		ans = (ans % 10) * (a % 10);
// 		a = a - 1 ;
// 		diff-- ;
// 	}
// 	return ans ;

// }


// bool is_suffix(string to_check, string mine) {
// 	if (mine.size() >= to_check.size()) return false ;
// 	// if (mine % 10 != to_check % 10) return false ;
// 	// int ll = to_check ;
// 	// int rr = mine ;
// 	// int count1  =0 ; int count2 =0 ;
// 	// while(ll){
// 	// 	count++ ;
// 	// 	ll = ll/10 ;
// 	// }
// 	int l = to_check.size() - 1 ; int r = mine.size() - 1 ;
// 	while (l >= 0 && r >= 0) {
// 		if (to_check[l] == mine[r]) {
// 			// to_check /= 10 ;
// 			// mine /= 10 ;
// 			l--; r-- ;
// 		}
// 		else return false ;
// 	}
// 	if (r >= 0) return false ;
// 	return true ;
// }

ll gcd(ll a, ll b) {
	if (b == 0) return a ;
	return gcd(b, a % b) ;
}


// void sieve(vector<int>primes,int n) {

// }

// void sieve_n(vector<int>n_primes,n) {
// 	for(int i =0 ; i<primes.size()-2 ; i++) {
// 		rep(j,primes.size()-1) {
// 			rep(k,primes.size()){

// 			}
// 		}
// 	}
// }


int find_tot(int to_find, vector<ll>&bot) {
	int l = 0 ; int r = bot.size() - 1 ;
	int count = 0 ;
	while (l < r) {
		if (bot[l] + bot[r] == to_find) {
			count++ ; l++ ; r-- ;
		}
		else if (bot[l] + bot[r] > to_find) {
			r-- ;
		}
		else l++ ;
	}
	return count ;

}


// void dijkstra(int source, vector < pair<int, int>graph[]) {
// 	ll parent[graph.size()] = { -1} ;
// 	ll dist[graph.size()]  = {INT_MAX - 1000} ;
// 	dist[source] = 0 ;
// 	parent[source] = source ;

// 	multiset<pair<int, int>> pq ;

// 	pq.insert({0, source}) ;

// 	while (!pq.empty()) {
// 		ll w = (*(pq.begin()).first) ;
// 		ll node = *(pq.begin()).second ;
// 		pq.erase(pq.begin()) ;
// 		for (int i = 0 ; i < graph[node].size() ; i++) {
// 			if (dist[graph[node][i].second] < graph[node][i].first + w) {
// 				dist[graph[node][i].second] = graph[node][i].first + w ;
// 				pq.insert({dist[graph[node][i].second], graph[node][i].second}) ;
// 				parent[graph[node][i].second] = node ;
// 			}
// 		}
// 	}
// }

// bool let_it(map<int, int> ff) {
// 	int rec = 0; int sq = 0 ;
// 	for (auto yo : ff) {
// 		if (yo.second >= 2) {
// 			rec++ ;
// 			ff[yo.first] -= 2 ;
// 		}
// 		if (yo.second >= 4) {
// 			sq++ ;
// 			ff[yo.first] -= 4 ;
// 		}
// 	}
// 	if (sq >= 1 && rec >= 2) return true ;
// 	return false ;
// }

// ll w, h , n ;

// bool b_search_fn(ll guess, vector<double>&ropes, int k) {
// 	int count = 0 ;
// 	rep(i, ropes.size()) {
// 		count = count + floor(ropes[i] / guess) ;
// 	}
// 	if (count <= k) {
// 		return true ;
// 	}
// 	return false ;



// // }
// // int dp[1100000] ;
// map<string, int>dp ;
// int recurse(vector<int>&coins, int sum, int index) {
// 	if (sum == 0) {
// 		return 1 ;
// 	}
// 	string ppp = to_string(sum) + "|" + to_string(index) ;
// 	if (dp[ppp] != 0) return dp[ppp] ;
// 	int yeah = 0 ;
// 	for (int i = index ; i < coins.size(); i++) {
// 		if (sum - coins[i] >= 0) {
// 			int pp = (recurse(coins, sum - coins[i], i)) % (1000000007);
// 			yeah = (yeah + pp) % (1000000007) ;
// 		}
// 	}
// 	return (dp[ppp] = yeah) ;
// }

// get ready for the atcoder contest baby ;
// contest no 178


int main() {
	fast ;
	ll a , b , c , d ;
	cin >> a >> b >> c >> d ;
	cout << max({a * c, a * d, b * c, b * d}) ;











}