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


















ll op(ll a, ll b){
    return a + b;
}

ll e(){
    return 0;
}

ll mapping(ll a, ll b){
    return a + b;
}

ll composition(ll a, ll b){
    return a + b;
}

ll id(){
    return 0;
}

int main(){
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    lazy_segtree<ll, op, e, ll, mapping, composition, id> tree(a);
    REP(i, n){
        cin >> a[i];
        tree.set(i, a[i]);
    }
    REP(i, Q){
        ll q;
        cin >> q;
        if(q == 0){
            ll p, x;
            cin >> p >> x;
            tree.set(p, tree.get(p) + x);
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << tree.prod(l, r) << endl;
        }
    }
}