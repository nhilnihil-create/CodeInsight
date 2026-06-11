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
		vector<LL> s(1<<n);
		REP(i, (1<<n)) cin >> s[i];
		// sort(ALL(s));
		// reverse(ALL(s));
		// // vector<LL> cur = {s[0]};
		// bool ex = true;
		// int p = 1;
		// REP(i, n) {
		// 	DEBUG(i);
		// 	REP(j, 1<<i) {
		// 		if(s[i] <= s[(1<<i) + i]) {
		// 			ex = false;
		// 			break;
		// 		}
		// 	}
		// 	if(!ex) break;
		// }
		// vector<LL> bt((1<<(n + 1)) - 1);
		// int p = 0;
		// bt[0] = s[0];
		// p++;
		// bool ex = true;
		// REP(i, SZ(s) - 1) {
		// 	bt[i * 2 + 1] = bt[i];
		// 	bt[i * 2 + 2] = s[p];
		// 	if(s[p] >= bt[i]) {
		// 		DEBUG(i);
		// 		ex = false;
		// 		break;
		// 	}
		// 	p++;
		// }
		// dpite(ALL(bt));
		multiset<LL> ss(ALL(s));
		vector<LL> cur = {*(--ss.end())};
		ss.erase(--ss.end());
		
		bool ex = true;
		while(!ss.empty()) {
			int len = SZ(cur);
			REP(i, len) {
				auto ite = ss.lower_bound(cur[i]);
				if(ite == ss.begin()) {
					ex = false;
					break;
				} else {
					ite--;
					cur.push_back(*ite);
					ss.erase(ite);
				}
			}
			if(!ex) break;
		}
		if(ex) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
