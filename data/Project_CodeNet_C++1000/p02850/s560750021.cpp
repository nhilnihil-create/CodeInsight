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

struct par{
	int nwn, id;
};

int cn, best;
int sol[MX];
vector<par> G[MX];

void dfs(int nod, int p, int c){
	int t = 0;
	for(auto i: G[nod]) if( i.nwn != p ){
		++t;
		if( t == c ) ++t;
		
		best = max(best, t);
		sol[i.id] = t;
		
		dfs(i.nwn, nod, t);
	}
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &cn);
    for(int i=1, a, b; i < cn; i++){
		scanf("%d%d", &a, &b);
		
		G[a].pb({b, i});
		G[b].pb({a, i});
	}
	
	dfs(1, -1, 0);
	
	printf("%d\n", best);
	for(int i=1; i < cn; i++)
		printf("%d\n", sol[i]);
    
   return 0;
}
