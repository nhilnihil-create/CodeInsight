#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
#define rep_d( i, n, m ) for(int i = ( n ) - 1; i >= ( m ); i--)
#define sort_asc( X ) sort(( X ).begin(), ( X ).end())
#define sort_desc( X ) sort(( X ).begin(), ( X ).end(), greater <>())

template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int* eratosthenes( int N );
bool bit_search( int pattern, int N );
template <class T> void cumulative_sum( T array, size_t N );

const ll INF = 1LL << 60;
// const int k_mod = 1e9 + 7;
const int k_mod = 998244353;

typedef struct {
	vector <int> to;
	int cost;
} edge;
typedef struct {
	int a;
	int b;
} P;

/*
 * @fn modpow
 * @brief O(logn): a^n % mod
 * @param a: 基数
 * @param n: 指数
 * @param mod: 法
 */
ll modpow( ll a, ll n, ll mod ) {
	ll res = 1;
	while (n > 0){
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
int main( void ){
	ll N, maximum = 0; cin >> N;
	vector <ll> v( N, 0 );
	rep( i, 0, N ){
		ll input; cin >> input;
		if (i == 0 && input != 0){
			cout << 0 << endl;
			return 0;
		}
		v[ input ]++;
		maximum = max( maximum, input );
	}
	bool can = ( v[ 0 ] == 1 );
	rep( i, 0, maximum + 1 )
	if (v[ i ] == 0)
		can = false;
	if (!can){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	rep( i, 1, N )
		ans = ( ans * modpow( v[ i - 1 ], v[ i ], k_mod )) % k_mod;
	cout << ans << endl;
}

int* eratosthenes( int N ){
	int* prime_array = new int[ N + 1 ];
	int lim = N;
	prime_array[ 0 ] = 0;
	prime_array[ 1 ] = 0;
	rep( i, 2, N + 1 ){
		prime_array[ i ] = 1;
	}
	rep( i, 2, lim ){
		if (prime_array[ i ] == 0)
			continue;
		lim = N / i;
		for(int j = i * 2; j < N + 1; j += i){
			prime_array[ j ] = 0;
		}
	}
	return prime_array;
}
template <class T> void cumulative_sum( T array, size_t N ) {
	rep( i, 1, N + 1 ){
		array[ i ] += array[ i - 1 ];
	}
}
template <class T> bool chmax( T& a, T b ) {
	if (a < b){
		a = b; return true;
	}
	return false;
}
template <class T> bool chmin( T& a, T b ) {
	if (a > b){
		a = b; return true;
	}
	return false;
}
bool bit_search( int pattern, int N ){
	int cnt = 0;
	rep( bit, 0, N ){
		if (pattern & ( 1 << bit )){
			cnt++;
		}
	}
	return true;
}
