#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
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
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

ll get(string &s){
    vector<int> v(8);
    rep(i,8) v[i] = s[i] - '0';
    ll ret = 0;
    ret += (v[0]*10+v[1])*3600 + (v[3]*10+v[4])*60 + v[6]*10+v[7];
    return ret;
}

ll dep[100000];
ll arr[100000];

int main(){
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        rep(i,n){
            string s,t; cin >> s >> t;
            dep[get(s)]++;
            arr[get(t)]++;
        }
        int ans = 0;
        int rest = 0;
        rep(i,86401){
            if(arr[i]){
                rest += arr[i];
            }
            if(dep[i]){
                if(rest < dep[i]){
                    ans += dep[i] - rest;
                    rest = 0;
                }else{
                    rest -= dep[i];
                }
            }
        }
        cout << ans << endl;
        rep(i,100000) dep[i] = arr[i] = 0;
    }
}
