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
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n,m; cin>>n>>m;
	vi v(n),a(n);
	rep(i,0,m)cin>>v[i]>>a[i];
	rep(i,0,1000000){
		string s=to_string(i);
		if(s.size()!=n)continue;
		bool ok=true;
		rep(j,0,m){
			int k=v[j]-1;
			if(s[k]!=(char)('0'+a[j])){
				ok=false;
			}
		}
		if(ok){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;

	return 0;
}