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
	int n; cin>>n;
	int ans=0;
	vi v(n);
	rep(i,0,n) cin>>v[i];
	rep(i,0,n-2){
		int a,b,c;
		a=v[i]; b=v[i+1]; c=v[i+2];
		bool ok=0;
		if(a<b && b<c)ok=1;
		if(c<b && b<a)ok=1;
	//	cout<<a<<b<<c<<" ";
		if(ok){
			ans++;
			//cout<<v[i+1]<<endl;
		}
		//else cout<<":("<<v[i+1]<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}