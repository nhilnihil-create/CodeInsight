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

const int LIM=1000010;
bool sosu[LIM];

int main() {
	int i;
	for(i=0;i<LIM;i++)sosu[i]=true;
	sosu[0]=sosu[1]=false;
	int j;
	for(i=0;i<LIM;i++){
		if(!sosu[i])continue;
		for(j=i+i;j<LIM;j+=i){
			sosu[j]=false;
		}
	}
	int a,d,n;
	while(a=in(),d=in(),n=in()){
		while(true){
			if(sosu[a]){
				n--;
				if(n==0)break;
			}
			a+=d;
		}
		cout<<a<<endl;
	}
	return 0;
}