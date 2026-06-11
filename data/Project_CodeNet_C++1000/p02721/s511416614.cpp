#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
 
#define init ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define setpr(x) cout << setprecision((x))
#define PI atan(1)*4
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define in insert
#define er erase
#define mk(a , b) { min((a) , (b)) , max((a) , (b)) }
#define flush cout.flush()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endc "\n"
#define MOD 998244353
#define mod(x) (x) %= MOD
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

// #define int ll
 
ll gcd(ll a, ll b){
    while(true){
        if(a>b)
            swap(a,b);
        if (a == 0) 
            return b; 
        ll p = b % a  , q = a;
        a = p;
        b = q;
    }
}
 
ll powerMod(ll x,ll y){
    ll res = 1;
    x %= MOD;
    while(y > 0){
        if(y & 1)res = (res*x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return res%MOD;
}
 
string binary(ll s) {
    string res = "";
    while(s != 0) {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin() , res.end());
    return res;
}


//  =========     /\       /|    |====/|
//      |        /  \       |    |   / |
//      |       /____\      |    |  /  |
//      |      /      \     |    | /   |
//  ========= /        \  =====  |/====|  
//  code

int32_t main(){
    init;
    int n,k,c,i,j,l,m,p;
    cin >> n >> k >> c;
    string st;
    cin >> st;
    set<int> s;
    set<int , greater<int> > gs;
    vector<int> lf , rt;

    for(i = 0; i < n; i++){
        if(st[i] == 'o'){
            s.in(i);
            gs.in(i);
        }
    }

    if(s.size() == 0){
        return 0;
    }

    i = *(s.begin());
    p = 1;
    lf.pb(i);
    while(true){
        if(p == k)
            break;
        auto it = s.lb(i + c + 1);
        if(it == s.end())break;
        i = *it;
        lf.pb(i);
        p++;
    }

    if(p < k)return 0;

    i = *(gs.begin());
    p = 1;
    rt.pb(i);
    while(true){
        if(p == k)
            break;
        auto it = gs.lb(i - c - 1);
        if(it == gs.end())break;
        i = *it;
        rt.pb(i);
        p++;
    }

    if(p < k)return 0;
    reverse(all(rt));
    for(i = 0; i < k; i++){
        if(lf[i] == rt[i])cout << lf[i] + 1 << endc;
    }
    return 0;
}