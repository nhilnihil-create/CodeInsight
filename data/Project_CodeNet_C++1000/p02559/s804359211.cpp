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
#include <complex>
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
const int MAX = 1020000;
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
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << "debug: " << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << "debug: " << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

template<typename T> struct BIT{
    vector<T> dat;
    ll sz;
    //all 1-indexed
    BIT(ll sz) : sz(sz){
        dat.assign(++sz, 0);
    }

    T sum(ll k){
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += dat[k];
        return (ret);
    }

    void add(ll k, T x){
        for(++k; k < dat.size(); k += k & -k) dat[k] += x;
    }
    
    ll get(T k){
        if(k <= 0) return 0; 
        ll ret = 0;
        int n = 1; while(n < sz) n *= 2;
        for(int i=n/2; i>0; i/=2){
            if(ret+i < sz && dat[ret+i] < k){
                k -= dat[ret+i];
                ret += i;
            }
        }
        return ret;
    }
};

int main(){
	int n,q; cin >> n >> q;
	BIT<ll> bit(n);
	rep(i,n){
		int a; cin >> a;
		bit.add(i,a);
	}
	while(q--){
		int t,a,b; scanf("%d%d%d",&t,&a,&b);
		if(!t){
			bit.add(a,b);
		}else{
			cout << bit.sum(b-1) - bit.sum(a-1) << "\n";
		}
	}
}