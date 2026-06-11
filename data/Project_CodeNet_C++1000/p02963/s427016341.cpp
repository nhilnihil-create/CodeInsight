#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll S;
    cin >> S;
    if(S == ll(1e18)) {
        cout << "0 0 0 1000000000 1000000000 0" << endl;
        return;
    }
    ll p = S/(ll)INF;
    ll q = S%(ll)INF;
    cout << 0 << " " << 0 << " " << ll(INF);
    cout << " " << ll(INF-q) << " " << 1 << " " << ll(p+1) << endl;
}

int main() {
    solve();
    return 0;
}