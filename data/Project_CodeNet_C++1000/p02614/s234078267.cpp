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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    int ans = 0;
    REP(maski,1<<h) REP(maskj,1<<w){
        int cnt = 0;
        REP(i,h) REP(j,w){
            if (((maski >> i) & 1) == 0) continue;
            if (((maskj >> j) & 1) == 0) continue;
            cnt += (s[i][j] == '#');
        }
        if (cnt == k) ans++;
    }
    cout << ans << endl;
    return 0;
}
