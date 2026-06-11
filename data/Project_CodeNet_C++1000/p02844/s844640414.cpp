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

signed main(){
	int n; cin>>n;
	string s; cin>>s;
	set<char> iset;
	set<char> ss;
	vi vec(n);
	int cnt=0;
	for(int i=n-1;i>=0;--i){
		if(!ss.count(s[i])){
			cnt++;
			ss.insert(s[i]);
		}
		vec[i]=cnt;
	}
	int ans=0;
	rep(i,0,n-2){
		if(iset.count(s[i]))continue;
		iset.insert(s[i]);
		set<char> jset;
		rep(j,i+1,n-1){
			if(jset.count(s[j]))continue;
			jset.insert(s[j]);
			ans+=vec[j+1];
		}
	}
	cout<<ans<<endl;
	return 0;
}