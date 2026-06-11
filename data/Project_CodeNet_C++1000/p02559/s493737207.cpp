#include<bits/stdc++.h>
#include<atcoder/all>
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr long long inf = 3e18;

signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;cin>>N>>Q;
	atcoder::fenwick_tree<int> bit(N);
	rep(i,N){
		int a;cin>>a;bit.add(i,a);
	}
	while(Q--){
		int t;cin>>t;
		if(!t){
			int p,x;cin>>p>>x;bit.add(p,x);
		}else {
			int l,r;cin>>l>>r;
			cout<<bit.sum(l,r)<<"\n";
		}
	}
}