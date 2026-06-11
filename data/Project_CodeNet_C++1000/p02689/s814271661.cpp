#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main(void){
    int n, m;
    cin >> n >> m;
    VI h(n);
    REP(i,n) h[i] = in();
    VVI e(n);
    REP(i,m){
        int u = in() - 1, v = in() - 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0;
    REP(i,n){
        bool f = true;
        for (int j : e[i]){
            if (h[i] <= h[j]) f = false;
        }
        ans += f;
    }
    cout << ans << endl;
    return 0;
}
