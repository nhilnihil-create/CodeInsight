#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(ll i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll X;
    cin >> X;
    FOR(i,-200,200) {
        FOR(j,-200,200) {
            ll a = i * i * i * i * i;
            ll b = j * j * j * j * j;
            if ((a-b) == X) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}