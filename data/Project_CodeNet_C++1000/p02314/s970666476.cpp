#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
 
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define ALL(X)      (X).begin(),(X).end()
typedef long long LL;
 
using namespace std;

static const int NMAX = 50000;
static const int MMAX = 20;
static const int INFITY = 1 << 29;

int main(){
	int n, m, C[MMAX+1], T[NMAX+1];
	cin >> n >> m;
	FOR(i,0,m){
		cin >> C[i];
	}

	FOR(j,0,NMAX){
		T[j] = INFITY;
	}

	T[0] = 0;
	//cout << C[0];
	FOR(i,0,m){
		FOR(j,C[i],n+1){
			T[j] = min(T[j], T[j-C[i]] + 1);
		}
	}

	cout << T[n] << endl;

	return 0;
}