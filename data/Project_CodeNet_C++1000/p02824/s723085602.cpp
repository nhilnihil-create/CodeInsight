#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef pair<int,int> PI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;
typedef pair<double,double> PD;

#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007

#define MAXS
LL n,m,v,p;
VL zb;

bool mozna(int p1){
	
	if(p1<0)
		return false;
	
	LL nad=m*(v-1);			//powiekszamy zb[p1] o m pkt
	int mks=p-1,prog=zb[p1]+m;
	
	REP(i,n){
		if(zb[i]>prog)
			mks--;
	}
	if(mks<0)
		return false;
	
	mks=p-1;
	FORD(i,n-1,0){
		if(i==p1)
			continue;
		if(mks){
			nad-=m;
			mks--;
		}
		else
			nad-=min(m,prog-zb[i]);
	}
//	cout<<p1+1<<" "<<zb[p1]<<" "<<nad<<"\n";
	return nad<=0;
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>v>>p;
	
	zb.resize(n);
	REP(i,n)
		cin>>zb[i];
	sort(ALL(zb));
	
	int k=n-1;
	for(int p1=n/2;p1>=1;p1/=2){
		while(mozna(k-p1))
			k-=p1;
	}
	cout<<n-k;
	
	return 0;
}
