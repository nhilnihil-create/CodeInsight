#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) true
#define dump(x) true
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	int N; cin >> N;
	using P = pair<ll,ll>;
	V<P> ps;
	rep(i,N){
		int x,y; cin >> x >> y;
		if(x==0 && y==0) continue;
		ps.emplace_back(x,y);
	}
	sort(all(ps),[&](P l,P r){
		return atan2(l.fs,l.sc) < atan2(r.fs,r.sc);
	});
	ll mx = 0;
	N = ps.size();
	rep(l,N){
		ll X=0,Y=0;
		rep(i,N){
			int j = (l+i)%N;
			X += ps[j].fs, Y += ps[j].sc;
			chmax(mx,X*X+Y*Y);
		}
	}
	cout << sqrt(mx) << endl;
}
