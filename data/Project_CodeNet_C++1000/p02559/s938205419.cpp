#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) <<
#include "atcoder/all"

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)

using namespace std;
using namespace atcoder;


int main(){
    int n, q;
    cin >> n >> q;
   
    fenwick_tree<ll> ft(n);
    rep(i,n){
        int a; cin >> a;
        ft.add(i,a);
    }

    while(q--){
        int t; cin >> t;
        if(t){
            int l, r; cin >> l >> r;
            cout << ft.sum(l, r) << endl;
        }else {
            int p; ll x;
            cin >> p >> x;
            ft.add(p, x);
        }
    }
}
