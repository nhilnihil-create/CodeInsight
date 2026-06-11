#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

void mainmain(){
	int h;
	while(cin>>h,h){
		vvint vv;
		initvv(vv,h,5);
		rep(i,h) rep(j,5){
			cin>>vv[i][j];
		}
		int ans = 0;
		rep(i,h) rep(j,5) ans += vv[i][j];
		bool update = true;
		int cnt = 0;
		while(1){
			update=false;
			vvint ww;
			if(cnt++>100) break;
			initvv(ww,h,5,0);
			rep(i,h){
				rep(j,3){
					if(vv[i][j]&&vv[i][j]==vv[i][j+1]&&vv[i][j]==vv[i][j+2]){
						ww[i][j]=ww[i][j+1]=ww[i][j+2]=1;
						update=true;
					}
				}
			}
			rep(i,h) rep(j,5){
				if(ww[i][j]) vv[i][j]=0;
			}
			for(int i=h-1;i>=0;i--){
				rep(j,5){
					if(vv[i][j]==0){
						int p = i-1;
						while(p >= 0){
							if(vv[p][j]){
								vv[i][j]=vv[p][j];
								vv[p][j]=0;
								break;
							}
							p--;
						}
					}
				}
			}
		}
		int tmp = 0;
		rep(i,h){
			rep(j,5){
				tmp += vv[i][j];
			}
		}
		cout<<ans-tmp<<endl;
	}
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}