#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template <class T, class U>ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >>p.second ;
	return is;
}
template <class T>istream& operator>>(istream& is,  vector<T>& v) {
	rep(i, v.size()) {
		is >> v[i];
	}
	return is;
}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n,k;
	ll ans=-INFLL;
	cin >>n>>k;
	vector<vector<pair<int, ll>>> tri(n, vector<pair<int,ll>>(33,mp(0,0LL)));
	VV up(n, V(33, 0LL));
	rep(i, n) { cin >> tri[i][0].F ;
		tri[i][0].F--;
		
	}
	rep(i, n) { cin >> tri[i][0].S;
		up[i][0] = tri[i][0].S;
	}
	rep(j,31){
		rep(i, n) { 
			tri[i][j + 1].F = tri[tri[i][j].F][j].F;
			tri[i][j + 1].S = tri[i][j].S+tri[tri[i][j].F][j].S;
			up[i][j + 1] =
			    max(up[i][j], tri[i][j].S + up[tri[i][j].F][j]);
		 }
	
	}
	/*
	rep(i,30){
		rep(j, n) { clog << tri[j][i] << " "; }
		clog << endl;
	}
	clog << endl;
	rep(i,30){
		rep(j, n) { clog << up[j][i] << " "; }
		clog << endl;
	}
	*/
	int at = 0;
	ll cnt = 0;
	for (int st = 0; st < n;st++){
		at = st;
		cnt = 0LL;
		for (int i = 0; k >= (1LL << i); i++) {
			if (k & (1LL << i)) {
				chmax(ans, cnt + up[at][i]);
				cnt += tri[at][i].S;
				at = tri[at][i].F;
				chmax(ans, cnt);
			//	clog << at <<" "<< cnt << endl;
			}
		}
	//	clog << ans << endl;
	    }cout << ans << endl;
}