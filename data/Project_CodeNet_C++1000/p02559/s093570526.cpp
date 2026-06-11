#include<bits/stdc++.h>
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

struct BIT{
	int N;
	vector<int>bit;
	void add(int x,int y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	int sum(int x){
		int res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
	int lower_bound(int w){
		if(w<=0)return 0;
		int x=0;
		int k=1;while(k*2<=N)k*=2;
		for(;k>0;k/=2){
			if(x+k<=N&&bit[x+k]<w){
				w-=bit[x+k];
				x+=k;
			}
		}
		return x+1;
	}
	BIT(int x):N(x),bit(x+1){}
};
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;cin>>N>>Q;
	BIT bit(N);
	rep(i,N){
		int a;cin>>a;
		bit.add(i+1,a);
	}
	while(Q--){
		int t,p,x;cin>>t>>p>>x;
		if(!t)bit.add(p+1,x);
		else cout<<bit.sum(x)-bit.sum(p)<<"\n";
	}
}