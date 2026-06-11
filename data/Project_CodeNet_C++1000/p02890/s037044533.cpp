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

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    REP(i,n){
        cnt[in()]++;
    }
    VI a(n + 1);
    for (P p : cnt) a[p.second]++;
    VI ans(n + 1);
    int d = n, s = n, c = 0;
    FOR(x,1,n){
        while (1){
            if ((x - c) * d <= s) break;
            c += a[d];
            s -= d * a[d];
            d--;
        }
        ans[x] = d;
    }
    FOR(x,1,n) printf("%d\n", ans[x]);

    return 0;
}
