#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)	for(ll i=(a); i<(b); i++)
#define REP(i,n)	FOR(i,0,(n))
typedef pair< ll, ll >	cp2;
typedef pair< ll, cp2 >	cp3;
const ll mod = 1000000007;
bool debug = false;


int N;
int A[1123];
int ans;

int main(){
	
	while( cin>>N, N ){
		ans = mod;
		REP( i, N ) cin>>A[i];
		sort( A, A+N );
		REP( i, N-1 ) ans = min( ans, A[i+1]-A[i] );
		if( debug ) cout<<"@ ";
		cout<<ans<<endl;
	}
	
	
	return 0;
}
