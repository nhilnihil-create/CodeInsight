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

int extgcd(int a,int b,int &x,int &y){
	int g=a;
	x=1,y=0;
	if(b!=0){
		g=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	return g;
}
 
// 逆元
int mod_inverse(int a,int m){
	int x, y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}
 
// 階乗
std::vector<int>fact;
void mod_fact(int n, int m){
	fact.resize(n+1);
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%m;
	}
}
 
// nCk mod p
int mod_nCr(int n, int k, int m){
	if(n<k)return 0;
	return fact[n]*mod_inverse(fact[k]*fact[n-k]%m,m)%m;
}

int N,K;
int A[100010],B[100010];
vector<int> G[100010];

void f(int s,int p,int &res,int d){
	int cnt=0;
	REP(i,G[s].size()){
		int e=G[s][i];
		if(e==p)continue;
		cnt++;
		f(e,s,res,d+1);
	}
	if(d==0){
		res*=mod_nCr(K-1,cnt,MOD);res%=MOD;
		res*=fact[cnt];res%=MOD;
	}
	else{
		res*=mod_nCr(K-2,cnt,MOD);res%=MOD;
		res*=fact[cnt];res%=MOD;
	}
}

signed main(){
	cin>>N>>K;
	mod_fact(100010,MOD);
	REP(i,N-1){
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	int res=1;
	f(0,-1,res,0);
	cout<<(res*K)%MOD<<endl;
	return 0;
}
