#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	ll res = 0;
	for(ll i = 1; i <= N; i++){
		ll x = N-i+1;
		res += x*(x+1)/2ll;
	}
	forn(i,0,N-1){
		ll u,v; cin >> u >> v;
		if(u > v)swap(u,v);
		res -= u*(N-v+1);
	}
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
