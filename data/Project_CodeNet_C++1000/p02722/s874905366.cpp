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
    ll n,i,j,k,l,p;
    cin >> n;
    p = 0;
    set<int> s , ans;
    for(i = 2LL; i * i <= n; i++){
        if(n % i == 0){
            s.in(n / i);
            s.in(i);
        }
    }

    for(auto i : s){
        k = n;
        while(k % i == 0)k /= i;
        l = (k - 1) / i;
        if(i * l == k - 1 || k == 1){
            ans.in(i);
        }
    }


    for(i = 1LL; i * i <= n - 1LL; i++){
        if((n - 1LL) % i == 0){
            if(n % i)
                ans.in(i);
            if(n % ((n - 1LL) / i))
                ans.in((n - 1LL) / i);
        }
    }

    ans.in(n);
    cout << ans.size() << endc;
    return 0;
}