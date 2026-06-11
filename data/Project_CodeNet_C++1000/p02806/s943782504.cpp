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
	map<string,int> mp;
	vi v(n+1);
	rep(i,1,n+1){
		string s; cin>>s;
		int a; cin>>a;
		mp[s]=i;
		v[i]=a+v[i-1];
	}
	string x; cin>>x;
	int j=mp[x];
	cout<<v[n]-v[j]<<endl;
	
	return 0;
}