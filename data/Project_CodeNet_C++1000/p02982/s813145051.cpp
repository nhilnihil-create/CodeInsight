#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n,d; cin>>n>>d;
	vvi v(n,vi(d));
	rep(i,0,n){
		rep(j,0,d){
			cin>>v[i][j];
		}
	}
	int ans=0;
	rep(i,0,n-1){
		rep(j,i+1,n){
			int l=0;
			rep(k,0,d){
				int p=(v[i][k]-v[j][k]);
				p*=p;
				l+=p;
			}
			//cout<<"l:"<<l<<endl;
			int y=sqrt(l);
			if(y*y==l) ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}