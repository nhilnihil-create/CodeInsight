#include <fstream>
#include <algorithm>
#include <deque>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<lli,lli>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

lli N, D, A, x, h;
deque<pii> msts;
deque<pii> ev; // location, subtract
// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D >> A;
    F0R(i,N) {
        cin >> x >> h;
        msts.PB(make_pair(x,h));
    }
    sort(msts.begin(), msts.end());

    lli ans = 0;
    lli dam = 0;
    while (!msts.empty()) {
        if (ev.empty() || msts[0].first <= ev[0].first) {
            pii cur = msts[0];
            msts.pop_front();
            if ((lli) cur.second - dam > 0) {
                lli num = (cur.second - dam + A - 1) / A;
                ans += num;
                ev.PB(make_pair(cur.first+2*D, num*A));
                dam += num*A;
            }
        } else {
            pii cur = ev[0];
            ev.pop_front();
            dam -= cur.second;
        }
    }
    cout << ans << '\n';
}