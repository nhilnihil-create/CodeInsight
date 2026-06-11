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
	int h,n;
	int ans=0;
	cin >>h>>n;
	VPi data(n);
	cin >> data;
	VVi dp(n+1, Vi(h + 3, INF));//at,hp-> mp
	dp[0][0] = 0;
	for (int i = 0; i < n;i++){
		for (int j = 0; j < h + 1;j++){
			chmin(dp[i+1][j],dp[i][j]);
			chmin(dp[i + 1][min(j + data[i].F, h)], dp[i+1][j] + data[i].S);
		} }
	cout << dp[n][h] << endl;
}