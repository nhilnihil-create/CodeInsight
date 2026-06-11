#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i];if(i<len-1) s<<" ";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i]<<endl;
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){
	s<<"{ ";
	for(auto itr=v.begin();itr!=v.end();++itr) {
		if (itr!=v.begin()) {s<< ", ";}
		s<<(*itr);
	}
	s<<" }";
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){
	s<<"{"<<endl;
	for(auto itr=m.begin();itr!=m.end();++itr){
		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;
	}
	s<<"}"<<endl;
	return s;
}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	map<int,int> mp;
	vector<ll> b;
	rep(i,n){
		int a;
		cin>>a;
		mp[a]++;
	}
	for(auto itr:mp){
		b.push_back(itr.se);
	}
	sort(begin(b),end(b));
	int m=b.size();
	vector<ll> sum(m+1,0);
	rep(i,m){
		sum[i+1]=sum[i]+b[i];
	}
	auto solve=[&](ll x,ll k){
		auto itr=lower_bound(begin(b),end(b),x);
		ll ret=sum[itr-begin(b)]+x*(end(b)-itr);
		return ret>=k*x;
	};
	FOR(k,1,n+1){
		ll ok=0,ng=INF,mid;
		while(ng-ok>1){
			mid=(ok+ng)/2;
			if(solve(mid,k)) ok=mid;
			else ng=mid;
		}
		cout<<ok<<endl;
	}
}