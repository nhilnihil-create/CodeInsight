#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(array##_itr, array) { cin >> *(array##_itr); }
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
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
long long modpow(long long a, long long n, long long mod=2019){
	long long res = 1;
	while (n > 0){
		if (n & 1)
		res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
int main(){
	string s;
	map<int, int> dis;
	cin >>s;
	dis[0]++;
	ll ans  = 0LL;
	int cnt = 0;
	rrep(i, s.size()) { 
		cnt +=(s[i]-'0')*modpow(10,s.size()-i-1);
		cnt %= 2019;
		dis[cnt]++;
	//	clog << cnt << endl;
	}
	repi(itr, dis) { //clog << itr->F << " " << itr->S << endl;
		ans += (ll)(itr->S) * (itr->S - 1) / 2;
	}
	cout<<ans<<endl;
}