#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
ll pcount(ll x) {return __builtin_popcountll(x);}
//const int mod = 1e9 + 7;
const int mod = 998244353;

int main(){
	int n; cin >> n;
	vl a(n); rep(i,n) cin >> a[i];
	map<ll,ll> mp;
	rep(i,n) mp[a[i]]++;
	if(n % 3 != 0){
		if(mp.size() == 1 && mp[0] == n){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	else{
		if(mp.size() == 3){
			ll exor = 0;
			ll num = -1;
			for(auto i : mp){
				exor ^= i.first;
				if(num == -1) num = i.second;
				else{
					if(num != i.second) num = -2;
				}
			}
			if(exor == 0 && num >= 0) puts("Yes");
			else puts("No");
		}else{
			if(mp.find(0) == mp.end()) puts("No");
			else{
				if(mp.size() == 1){
					puts("Yes");
					return 0;
				}
				if(mp.size() == 2){
					if(mp[0] == n/3) puts("Yes");
					else puts("No");
				}
				else puts("No");
			}
		}
	}
}