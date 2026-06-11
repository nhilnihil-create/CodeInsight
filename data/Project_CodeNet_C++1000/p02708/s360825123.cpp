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
    int N,K;
    cin >> N >> K;
    // vmx[i] i個選んだ時の最大値
    vector<ll> vmx(N+2,0);
    vector<ll> vmn(N+2,0);
    REP(i,N+1) {
        vmx[i+1] = (N-i) + vmx[i];
        vmn[i+1] = i + vmn[i];
    }
    ll sm = 0;
    FOR(i,K,N+2) sm+= (vmx[i]-vmn[i]+1);

    cout << (sm%ll(1e9+7)) << endl;
}

int main() {
    solve();
    return 0;
}
