#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

typedef long long ll; 
typedef long double ld;
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (300006)
ll T[2], A[2], B[2];
int main()
{
	cin>>T[0]>>T[1]>>A[0]>>A[1]>>B[0]>>B[1];
	if(T[0]*A[0]+T[1]*A[1] == T[0]*B[0]+T[1]*B[1]) return cout<<"infinity\n", 0; 
	if(A[0] > B[0]) swap(A[0], B[0]), swap(A[1], B[1]);
	if(A[0]==B[0]) {
		return cout<<"infinity\n", 0; 
	}
	if(T[0]*B[0]+T[1]*B[1] > T[0]*A[0]+T[1]*A[1]) return cout<<0, 0;
	ll diff=(T[0]*A[0]+T[1]*A[1])-(T[0]*B[0]+T[1]*B[1]);
	// cerr<<diff<<'\n';
	cout<<(ll)ceill(((B[0]-A[0])*T[0]+1)/(ld)diff)*2-1-(((B[0]-A[0])*T[0])%diff==0?1:0)<<'\n';
}
