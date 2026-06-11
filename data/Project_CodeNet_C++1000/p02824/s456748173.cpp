#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,m,p,v;
Vi a;

bool ck(ll id){
	ll v2 = v*m;
	v2 -= m*p;//idの問題と上からp-1問の問題.
	v2 -= id*m;//idより小さい問題.
	if(v2<0){
		if(a[a.size()-p]<=a[id]+m)return true;
		else return false;
	}else{
		ll now = a[id]+m;
		if(now<a[a.size()-p])return false;
		repi(j,id+1,a.size()-p+1){
			if(now-a[j]<0){
				break;
			}
			v2 -= now-a[j];
			if(v2<=0){
				break;
			}
		}
		if(v2<=0)return true;
		else return false;
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n>>m>>v>>p;
	a.resize(n);
	rep(i,n){
		cin>>a[i];
	}
	sort(all(a));
	ll mid, ok = a.size()-1, ng = -1;
	while(abs(ok-ng)>1){
		mid = (ok+ng)/2;
		if(ck(mid))ok = mid;
		else ng = mid;
	}//midではなくokを使わないとバグる!
	//ck(0);
	print(a.size()-ok);
	return 0;
}