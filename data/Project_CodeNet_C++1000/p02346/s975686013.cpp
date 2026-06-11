#include <bits/stdc++.h>
 
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const long INF=pow(2,31)-1;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
const long P_SIZE=301;
const long MAX_N=100004;
int bit[MAX_N+1];
int N;
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

void add(int i,int x){
	while(i<=N){
		bit[i]+=x;
		i+=i&-i;
	}
}

int main(){
	int Q;
	cin>>N>>Q;
	CLR(bit);	
	REP(i,Q){
		long c,x,y;
		cin>>c>>x>>y;
		if(c==0){
			add(x,y);
		}else{
			cout<<sum(y)-sum(x-1)<<endl;
		}
	}
	//REP(i,SZ(res))cout<<res[i]<<endl;
	return 0;
}