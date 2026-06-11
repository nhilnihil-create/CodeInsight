#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int MOD = 1000000007;
//const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    int h, w; cin >> h >> w;
    int a, b; cin >> a >> b;
    vector<vector<int>> ar(h, vector<int>(w,0));
    if (a == 0 && b == 0){}
    else if (a == 0){
        rep(i,b) rep(j,w) ar[i][j] = 1;
    }
    else if (b == 0){
        rep(i,h) rep(j,a) ar[i][j] = 1;
    }
    else {
        rep(i,b) rep(j,a) ar[i][j] = 1;
        repp(i,h,b) repp(j,w,a) ar[i][j] = 1;
    }
    rep(i,h){
        rep(j,w) cout << ar[i][j];
        cout << endl;
    }
}