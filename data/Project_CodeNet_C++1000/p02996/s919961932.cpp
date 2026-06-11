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
using pl=pair<ll,ll>;

signed main(){
	ll n; cin>>n;
	vector<pl> v(n);
	rep(i,0,n)cin>>v[i].second>>v[i].first;
	sort(all(v));
	ll cnt=0;
	rep(i,0,n){
		cnt+=v[i].second;
		if(cnt>v[i].first){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	
	
	return 0;
}