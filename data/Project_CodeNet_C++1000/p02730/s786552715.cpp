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
	string s; cin>>s;
	int n=s.size();
	string t=s;
	reverse(all(t));
	if(s!=t){
		cout<<"No"<<endl;
		return 0;
	}
	int a=(n-1)/2;
	int b=(n+3)/2-1;
	string k,l;
	rep(i,0,a){
		k.push_back(s[i]);
	}
	rep(i,b,n){
		l.push_back(s[i]);
	}
//	cout<<k<<endl<<l<<endl;
	if(k==l)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}