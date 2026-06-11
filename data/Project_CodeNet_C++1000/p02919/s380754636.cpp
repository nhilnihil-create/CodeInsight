#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#pragma GCC optimize ("O3")
	#define NDEBUG
#endif
// #define _USE_MATH_DEFINES
#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { os << '(' << p.first << ' ' << p.second << ')'; return os; }

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
	template<typename T> void dpite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
#else
	#define DEBUG(x) true
	template<typename T> void dpite(T a, T b){ return; }
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
template<typename T> void pite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

const array<int, 4> dx = {0, 1, 0, -1};
const array<int, 4> dy = {1, 0, -1, 0};


typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);
}

int main()
{
	ios_init();
	int n;
	while(cin >> n) {
		vector<int> p(n);
		vector<int> rp(n);
		REP(i, n) {
			cin >> p[i];
			p[i]--;
			rp[p[i]] = i;
		}
		set<int> se;
		// se.insert(-2);
		// se.insert(-1);
		// se.insert(n);
		// se.insert(n + 1);
		LL ans = 0;
		RREP(i, n) {
			int cur = rp[i];
			LL a = 0, b = 0, c = 0, d = 0;
			auto rite = se.lower_bound(cur);
			if(rite != se.end()) {
				c = *rite - cur;
				int t = *rite;
				rite++;
				if(rite == se.end()) {
					d = n - t;
				} else {
					d = *rite - t;
				}
			} else {
				c = n - cur;
			}

			auto lite = se.lower_bound(cur);
			if(lite != se.begin()) {
				lite--;
				b = cur - *lite;
				int t = *lite;
				if(lite != se.begin()) {
					lite--;
					a = t - *lite;
				} else {
					a = t + 1;
				}
			} else {
				b = cur + 1;
			}

			// lite--;
			// LL b = cur - *lite - 1;
			// LL c = 0
			// if(rite != se.end()) {

			// }
			// if(lf) {
			// 	b = 0;
			// }
			// LL d = 0;
			// {
			// 	LL x = *rite;
			// 	rite++;
				
			// 	d = *rite - x;
			// }
			// LL a = 0;
			// {
			// 	LL x = *lite;
			// 	lite--;
			// 	a = x - *lite;
			// }
			DEBUG(a); DEBUG(b); DEBUG(c); DEBUG(d);
			ans += (i + 1) * (a * c + b * d);
			// {
			// 	int x = *rite;
			// 	rite++;
			// 	if(rite != se.end()) {

			// 	}
			// }
			se.insert(rp[i]);
			dpite(ALL(se));
		}
		cout << ans << endl;
	}
	return 0;
}
