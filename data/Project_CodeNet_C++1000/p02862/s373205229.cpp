/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int64 pot(int64 base, int64 e){
	int64 ans = 1;
	
	while( e ){
		if( e & 1ll ) ans = ans * base % MOD;
		base = base * base % MOD;
		e >>= 1ll;
	}
	return ans;
}

int64 inv_mod(int a, int b){
	return a * pot(b, MOD-2) % MOD;
}

int x, y;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &x, &y);
    
    if( (x + y) % 3 != 0  )
		return !printf("0\n");
	
    int p = (x + y) / 3;
    int f = x - p;
	
	if( f < 0 || p - f < 0 )
		return !printf("0\n");
		
    //~ db() << imie(p) imie(f) << imie(p-f);
    
    int64 fact = 1;
    for(int i=2; i<=p; i++){
		fact *= i;
		fact %= MOD;
	}
	
	int64 den = 1;
	for(int i=2; i<=f; i++){
		den *= i;
		den %= MOD;	
	}
	
	for(int i=2; i<=p-f; i++){
		den *= i;
		den %= MOD;	
	}
	
	//~ db() << imie(fact) imie(den);
	
	fact = inv_mod(fact, den);
	
	printf("%lld\n", fact);
    
   return 0;
}
