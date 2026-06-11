#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>

using namespace std;
#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define INT(a) int((a)+1e-9)
int DX[4]={1,0,-1,0};
int DY[4]={0,1,0,-1};

typedef pair<int,int> Pii;


#define SUPnl 10002

int nl;
int p[SUPnl];

int init(){REP(ni,nl){p[ni]=-1;}}

int getRoot(int a){
	while(true){
		if(p[a]==-1) return a;
		a=p[a];
	}
}

bool same(int a, int b){
	return getRoot(a)==getRoot(b);
}

void unite(int a, int b){
	a=getRoot(a);
	b=getRoot(b);
	if(a==b) return;
	p[b]=a;
}

int main(){
	int ol;
	cin>>nl>>ol;
	init();
	int ot,a,b;
	REP(oi,ol){
		cin>>ot>>a>>b;
		if(ot==0) unite(a,b);
		if(ot==1) cout<<same(a,b)<<endl;
	}
}