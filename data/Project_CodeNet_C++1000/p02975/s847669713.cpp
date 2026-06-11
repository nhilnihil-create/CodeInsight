#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
 
signed main(){
	int N;
	cin>>N;
	map<int,int>m;
	rep(i,N){
		int a;cin>>a;m[a]++;
	}	
	
	if(N%3){
		if(m[0]==N){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	else{
		bool ok=true;
		int x=0;
		N/=3;
		for(auto p:m){
			if(p.se%N)ok=false;
			rep(i,p.se/N)x^=p.fi;
		}
		if(x)ok=false;
 
		if(ok)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}