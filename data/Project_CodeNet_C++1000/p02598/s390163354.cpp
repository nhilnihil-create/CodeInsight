#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
// using namespace boost::multiprecision;

typedef long long ll;
typedef long double ld;

#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mll map<ll,ll>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep1(i,n) for(int i=1; i<=(int)(n); i++)
#define all(c) c.begin(),c.end()
#define srta(a) sort(all(a))
#define srtd(a) sort(all(a),greater<型>())
#define rvs(s) reverse(all(s))
#define psb push_back
#define ppb pop_back
#define isu isupper
#define isl islower
#define lb(a,k) lower_bound(all(a),k)
#define ub(a,k) upper_bound(all(a),k)
#define bs(a,k) binary_search(all(a),k)
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int I_INF = 1001001001;
const ll LL_INF = 1001001001001001001;
const ld EPS = 0.001;

bool ok(ll N, ll K, vl a, ll mid) {
    ll ck = 0;
    rep (i, N) ck += (a[i]-1)/mid;
    return ck <= K;
}

int main() {
    ll N, K;
    cin >> N >> K;

    vl a(N);
    ll m = 0;
    rep (i, N) {
        cin >> a[i];
        chmax(m, a[i]);
    }

    // l:NG, r:OK
    int l = 0, r = m+1;
    while (r-l > 1) {
        ll mid = (l+r)/2;
        (ok(N, K, a, mid) ? r : l) = mid;
    }

    cout << r << endl;
}
