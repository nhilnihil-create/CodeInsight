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

int N, K;
int P[MX];
char A[MX];
set<int> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &N, &K);
	scanf(" %s", &A);
	
	for(int i=N; i > 0; i--){
		if( A[i] == '0' )
			S.insert(i);
		
		if( i+K <=N ){ 
			S.erase(i+K);
			
			if( S.empty() )
				return !printf("-1\n");
				
			P[i+K] = *S.begin();
		}
	}
	
	//~ db() << mt(P, N);
	
	vector<int> sol;
	int p = N;
	while( p > 0 ){
		sol.pb(p - P[p]);
		p = P[p];
	}
	
	reverse(all(sol));

	for(size_t i=0; i < sol.size(); i++)
		printf(i == sol.size()-1 ? "%d\n" : "%d ", sol[i]);
    
   return 0;
}
