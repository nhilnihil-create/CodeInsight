#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

vector<int> list;
vector<int> kisu;

int dp1[1001000];
int dp2[1001000];

int main() {
	int i;
	for(i=1;;i++){
		int yon=i*(i+1)*(i+2)/6;
		if(yon>1000000)break;
		list.push_back(yon);
		if(yon%2==1)kisu.push_back(yon);
	}
	for(i=0;i<1001000;i++){
		dp1[i]=dp2[i]=i;
	}
	for(i=0;i<1001000;i++){
		int j;
		for(j=0;j<list.size();j++){
			if(i-list[j]<0)break;
			chmin(dp1[i],dp1[i-list[j]]+1);
		}
		for(j=0;j<kisu.size();j++){
			if(i-kisu[j]<0)break;
			chmin(dp2[i],dp2[i-kisu[j]]+1);
		}
	}
	int n;
	while(n=in()){
		cout<<dp1[n]<<" "<<dp2[n]<<endl;
	}
	return 0;
}