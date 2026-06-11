//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int  n;
int res[505][505];
void dfs(int start,int to,int index){
	if(to-start+1<=1) return;
	rb(i,start,to)
		rb(j,i+1,to) res[i][j]=index;
	int mid=(start+to)>>1;
	dfs(start,mid,index+1),dfs(mid+1,to,index+1); 
}
int main(){
	cin>>n;
	dfs(1,n,1);
	rb(i,1,n){
		rb(j,i+1,n) cout<<res[i][j]<<" ";cout<<endl;
	}
	return 0;
}