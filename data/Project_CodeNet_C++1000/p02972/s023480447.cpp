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
//priority_queue<ll, vector<ll>, greater<ll>> q;
signed main(){
	ll n; cin>>n;
	vl a(n+10); rep(i,1,n+1)cin>>a[i];
	vl cnt(n+10),ans(0);
	for(ll i=n;i>=1;--i){
		if(cnt[i]%2!=a[i]){
			ans.push_back(i);
			for(ll j=1;j*j<=i;j++){
				if(i%j==0){
					cnt[j]++;
					if(j!=i/j)cnt[i/j]++;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	rep(i,0,ans.size())cout<<ans[i]<<" ";
	cout<<endl;

	
	return 0;
}