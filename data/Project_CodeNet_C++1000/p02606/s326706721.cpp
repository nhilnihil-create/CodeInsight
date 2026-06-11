#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
#define rep_d( i, n, m ) for(int i = ( n ) - 1; i >= ( m ); i--)
#define sort_asc( X ) sort(( X ).begin(), ( X ).end())
#define sort_desc( X ) sort(( X ).begin(), ( X ).end(), greater <>())
#define endl "\n"


template <typename T, typename K> struct P {
	T a; K b;
};

template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int* eratosthenes( int N );
bool bit_search( int pattern, int N );
vector <P <ll, ll> >prime_factorize( ll N );
ll pow( ll a, ll n );
void initialize( void );

const ll INF = 1LL << 60;
const int k_mod = 1e9 + 7;
int main( void ){
	// initialize();
	int L, R, d;
	cin >> L >> R >> d;
	cout << abs((( L - 1 ) / d ) - ( R / d )) << endl;
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

/*
 * @fn eratosthenes
 * @brief O(NloglogN)~=(N)
 * @param N: その数まで
 * @return 0 or 1 の配列 (boolは都合が悪い)
 */
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
bool bit_search( int pattern, int N ){
	int cnt = 0;
	rep( bit, 0, N ){
		if (pattern & ( 1 << bit )){
			cnt++;
		}
	}
	return true;
}

/*
 * @fn prime_factorize
 * @brief O(√N): 素因数分解
 * @param N: 素因数分解する数
 * @return vec: (a: 素数, b: 個数)
 */
vector <P <ll, ll> >prime_factorize( ll N ){
	vector <P <ll, ll> > vec;
	int lim = sqrt( N ) + 1;
	rep( i, 2, N + 1 ){
		if (i >= lim){
			vec.push_back( P <ll, ll>{N, 1} );
			break;
		}
		if (N % i == 0){
			vec.push_back( P <ll, ll>{i, 0} );
			while(N % i == 0){
				N /= i;
				vec.back().b++;
			}
		}
	}
	return vec;
}
/*
 * @fn pow
 * @brief a^n
 * @param a: 基数
 * @param n: 指数
 */
ll pow( ll a, ll n ) {
	ll res = 1;
	while (n > 0){
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

void initialize( void ){
	cout << fixed << setprecision( 10 );
}
