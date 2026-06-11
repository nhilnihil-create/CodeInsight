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
	cout<<fixed<<setprecision(10);
	int n,k; cin>>n>>k;
	vector<double> vec(n);
	rep(i,0,n){
		double a; cin>>a;
		double f=(a+1)/2;
		vec[i]=f;
	}
	double ans=0.0;
	double memo=0.0;
	rep(i,0,n){
		memo+=vec[i];
		if(i>=k){
			memo-=vec[i-k];
		}
		//cout<<"memo:"<<memo<<endl;
		chmax(ans,memo);
	}
	cout<<ans<<endl;
	
	return 0;
}