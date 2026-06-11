#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

/*
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif
*/
#define pb push_back
#define mp make_pair

typedef long long int ll;

float ans = 0;

ll GCD(ll a, ll b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

void solve(){
	int h,w,a,b;
	scanf("%d%d%d%d",&h,&w,&a,&b);
	int v[h][w];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++) v[i][j] = 0;
	}

	for(int i=0; i<b; i++){
		for(int j=0; j<w; j++) v[i][j] = 1;
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<a; j++){
			if(v[i][j]==1) v[i][j] = 0;
			else v[i][j] = 1;
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++) cout<<v[i][j];
		cout<<endl;
	}
}


int main(int argc, char const *arga[])
{	
	ll cant;
	//scanf("%lld",&cant);
	cant = 1;
	while(cant--) solve();
}