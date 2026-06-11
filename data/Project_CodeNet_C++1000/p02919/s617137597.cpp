#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> void chmax(T& x, U y){if(x<y) x=y;}
template<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N; cin >> N;
	V<int> A(N); rep(i,N) cin >> A[i], A[i]--;
	V<int> iA(N); rep(i,N) iA[A[i]] = i;
	set<int> st;
	st.insert(-1);st.insert(N);
	st.insert(-2);st.insert(N+1);
	ll ans = 0;
	per(v,N){
		int x = iA[v];
		int l=0,l2=0,r=0,r2=0;
		{
			auto it = st.lower_bound(x);
			r = *it;
			it++;
			r2 = *it;
			it--;
			it--;
			l = *it;
			it--;
			l2 = *it;
			it++;
		}
		ll num = 0;
		if(r != N) num += ll(x-l) * (r2-r);
		if(l != -1) num += ll(r-x) * (l-l2);
		ans += num * (v+1);
		st.insert(x);
	}
	cout << ans << endl;
}
