#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

pint operator+(pint a,pint b){
	return pint(a.fi+b.fi,a.se+b.se);
}
pint operator-(pint a,pint b){
	return pint(a.fi-b.fi,a.se-b.se);
}

signed main(){
	int N;cin>>N;
	vpint ps(N);
	rep(i,N)cin>>ps[i].fi>>ps[i].se;

	int ma=0;
	rep(i,N)rep(j,N){
		if(i==j)continue;
		pint d=ps[j]-ps[i];
		int cnt=0;
		rep(k,N)rep(l,N)if(ps[l]-ps[k]==d)cnt++;
		chmax(ma,cnt);
	}
	cout<<N-ma<<endl;
	return 0;
}