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

struct v{
	double x,y,ang;
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<v> p(2*n);
	rep(i,n){
		cin>>p[i].x>>p[i].y;
		p[i+n].x=p[i].x;
		p[i+n].y=p[i].y;
		p[i].ang=atan2(p[i].y,p[i].x);
		p[i+n].ang=p[i].ang+2*PI;
	}
	double ans=0;
	sort(begin(p),end(p),[](const v &a,const v &b){
		return a.ang<b.ang;
	});
	vector<double> sx(2*n+1,0),sy(2*n+1,0);
	rep(i,2*n){
		sx[i+1]=sx[i]+p[i].x;
		sy[i+1]=sy[i]+p[i].y;
	}
	rep(i,n)FOR(j,i,2*n){
		if(p[j].ang-p[i].ang>PI+EPS) break;
		double nx=sx[j+1]-sx[i],ny=sy[j+1]-sy[i];
		chmax(ans,nx*nx+ny*ny);
	}
	cout<<setprecision(15)<<sqrt(ans)<<endl;
}