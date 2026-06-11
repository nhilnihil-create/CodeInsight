#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const int PI = acos(-1);
int main(){
	int a,b,m;cin>>a>>b>>m;
	int A[a],B[b];
	int am =INF,bm=INF;
	rep(i,a){
		cin>>A[i];
		am =min(am,A[i]);
	}
	rep(i,b){
		cin>>B[i];
		bm =min(bm,B[i]);
	}
	int ans =am+bm;
	rep(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		x--;y--;
		ans=min(ans,A[x]+B[y]-z);
	}
	cout<<ans<<endl;
}