#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H);
    REP(i, H) cin >> s[i];
    ll ans = 0;
    REP(i, 1 << H)REP(j,1 << W){
        vector<string> f(H);
        REP(k, H) f[k] = s[k];
        REP(k, H) if ((i >> k) % 2 == 0) REP(l, W) f[k][l] = '.';
        REP(k, W) if ((j >> k) % 2 == 0) REP(l, H) f[l][k] = '.';
        ll tmp = 0;
        REP(k, H)REP(l, W) if (f[k][l] == '#') tmp++;
        if (tmp == K) ans++;
    }
    cout << ans << endl;


    return 0;
}
