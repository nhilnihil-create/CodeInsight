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
#include<unordered_set>
#include<unordered_map>
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

int N;
int A[100010];
set<int> U;
map<int,int> H;
int C[5];
int B[100010];

void solve(int a,int b){
	REP(i,N){
		B[i]=0;
	}
	REP(i,N){
		if(i%3==0){
			B[i]=a;
		}
		else if(i%3==1){
			B[i]=b;
		}
		else{
			B[i]=a^b;
		}
	}
	bool flag=true;
	sort(B,B+N);
	REP(i,N){
		if(A[i]!=B[i]){
			flag=false;
		}
	}
	if(flag==true){
		cout<<"Yes"<<endl;
		exit(0);
	}
}

signed main(){
	cin>>N;
	REP(i,N){
		cin>>A[i];
		U.insert(A[i]);
		H[A[i]]++;
	}
	sort(A,A+N);
	vector<int> v(U.begin(),U.end());
	if(U.size()>=4){
		cout<<"No"<<endl;
		return 0;
	}
	else if(U.size()==1){
		solve(v[0],v[0]);
	}
	else if(U.size()==2){
		solve(v[0],v[1]);
		solve(v[1],v[0]);
	}
	else{
		solve(v[0],v[1]);
		solve(v[1],v[0]);
		solve(v[1],v[2]);
		solve(v[2],v[1]);
		solve(v[0],v[2]);
		solve(v[2],v[0]);
	}
	cout<<"No"<<endl;
	return 0;
}
