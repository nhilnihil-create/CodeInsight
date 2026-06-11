#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
#include<deque>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define DEB2(X) cout<<X<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define DEB2(X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
//typedef std::pair<int,int> P;
struct edge{int to,cost;};
const int INF=100000000000000000;
const int INF2=9223372036854775807;
const int MOD=1000000007;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define min(X,Y) (((int)(X)<(int)(Y))?(X):(Y))
#define max(X,Y) (((int)(X)>(int)(Y))?(X):(Y))
#define NP(X,Y) next_permutation(X,Y)
#define setdouble(X,Y) cout<<fixed<<setprecision(X)<<Y
int ceil2(int a,int b){if(a%b==0){return a/b;}else{return a/b+1;}}
int pow2(int a,int b){int r=1;for(int i=1;i<=b;i++){r*=a;}return r;}
int Log2(int a){int t=0;while(1){if(a==0||a==1){break;}a/=2;t++;}return t;}

int N,K;
int A[200010];
int num[200010];

void calc(){
	REP(i,N){
		num[i]=0;
	}
	REP(i,N){
		int l=max(0,i-A[i]);
		int r=min(N-1,i+A[i]);
		num[l]++;
		num[r+1]--;
	}
	REP(i,N){
		num[i+1]+=num[i];
	}
	REP(i,N){
		A[i]=num[i];
	}
}

signed main(){
	cin>>N>>K;
	REP(i,N){
		cin>>A[i];
	}
	REP(i,min(50,K)){
		calc();
	}
	REP(i,N){
		cout<<A[i];
		if(i<N-1)cout<<" ";
	}
	cout<<endl;
	return 0;
}
