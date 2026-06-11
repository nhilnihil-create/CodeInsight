#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn =  200;
double a, b, x;

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> a >> b >> x;
    
    x /= a;
    double y = x - a*b/2;
    double ret;
    if (y >= 0) {
        double l = 2*y/a;
        ret = atan2(a, b-l);
    } else{
        double l = 2*x/b;
        ret = atan2(l, b);
    }
    ret = 90 - ret*180/M_PI;

    cout << std::fixed << std::setprecision(10) << ret << "\n";
}