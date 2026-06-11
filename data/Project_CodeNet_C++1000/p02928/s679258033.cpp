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
const int k_mod = 1e9 + 7;

typedef struct {
	vector <int> to;
	int cost;
} edge;
typedef struct {
	int a;
	int b;
} P;
int main( void ){
	ll N, K; cin >> N >> K;
	vector <int> input( N );
	vector <P> n( N );
	rep( i, 0, N )
	cin >> input[ i ];
	rep( i, 0, N ){
		int cnt_a = 0, cnt_b = 0;
		rep( j, i + 1, N )
		if (input[ i ] > input[ j ])
			cnt_a++;
		rep_d( j, i, 0 )
		if (input[ i ] > input[ j ])
			cnt_b++;
		n[ i ] = P{cnt_a, cnt_b};
	}
	ll sum_a = 0, sum_b = 0;
	rep( i, 0, N ){
		sum_a += n[ i ].a;
		sum_b += n[ i ].b;
	}
	ll k_a = ( K * ( K + 1 ) / 2 ) % k_mod;
	ll k_b = ( K * ( K - 1 ) / 2 ) % k_mod;
	sum_a = ( sum_a * k_a ) % k_mod;
	sum_b = ( sum_b * k_b ) % k_mod;
	cout << ( sum_a + sum_b ) % k_mod << endl;
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
