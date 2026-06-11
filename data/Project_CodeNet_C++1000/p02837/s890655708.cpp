#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//__builtin_popcount(n)
using pi = pair<int,int>;
signed main(){
	int n; cin>>n;
	vector<vector<pi>> vec(n,vector<pi>(0));
	rep(i,0,n){
		int a; cin>>a;
		rep(j,0,a){
			int x,y; cin>>x>>y;
			--x;
			vec[i].push_back(make_pair(x,y));
		}
	}
	int ans=0;
	rep(i,0,1<<n){
		bool ok=true;
		rep(j,0,n){
			if(i>>j&1){
				for(auto c:vec[j]){
					int a=c.first,b=c.second;
					if(((i>>a)&1)==b);
					else ok=false;
				}
			}
		}
		if(ok)chmax(ans,__builtin_popcount(i));
	}
	cout<<ans<<endl;
	return 0;
}