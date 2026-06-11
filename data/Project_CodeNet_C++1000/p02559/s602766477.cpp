#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>
#include <atcoder/all>


using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;


#define REP(i, n) for(ll i = 0; i < n; i++)





















int main(){
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    fenwick_tree<ll> tw(n);
    REP(i, n){
        cin >> a[i];
        tw.add(i, a[i]);
    }
    REP(i, Q){
        ll q;
        cin >> q;
        if(q == 0){
            ll p, x;
            cin >> p >> x;
            tw.add(p, x);
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << tw.sum(l, r) << endl;
        }
    }
}