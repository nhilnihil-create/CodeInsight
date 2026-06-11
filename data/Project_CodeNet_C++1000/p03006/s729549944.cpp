#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

#define MOD_BIG 1000000007
#define MOD_BIG2 998244353
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////



//////////////////////////////////////

int main() {
    
    int N;
    cin >> N;
    vector<pll> B(N);
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        B[i] = pll(x, y);
    }
    std::sort(B.begin(), B.end());
    std::set<pll> s;
    FOR(i, 0, N) FOR(j, i+1, N) {
        ll dx = B[j].first - B[i].first;
        ll dy = B[j].second - B[i].second;
        s.insert(pll(dx, dy));
    }
    int ans = N;
    while(!s.empty()) {
        int cnt = 0;
        ll mx, my;
        mx = (*s.begin()).first;
        my = (*s.begin()).second;
        s.erase(s.begin());
        FOR(i, 0, N) {
            FOR(j, i+1, N) {
                ll dx = B[j].first - B[i].first;
                ll dy = B[j].second - B[i].second;
                if (dx == mx && dy == my) cnt++;
                if (dx > mx) break;
            }
        }
        ans = std::min(ans, N-cnt);
        //cerr << N - cnt << endl;
    }
    cout << ans << endl;
    
    return 0;
}
