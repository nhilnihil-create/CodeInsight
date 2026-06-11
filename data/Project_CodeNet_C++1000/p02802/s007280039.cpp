#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N, M; cin >> N >> M;
    vector<bool> ac(N + 1, false);
    map<int, int> wa;

    ll acc = 0;
    rep(i, M) {
        ll p; string S; cin >> p >> S;
        if (S == "WA" && !ac[p]) wa[p]++;
        else if (S == "AC" && !ac[p]) {
            ac[p] = true; acc++;
        }
    }

    ll wrn = 0;
    reps(i, N) {
        if (ac[i]) wrn += wa[i];
    }
    cout << acc << " " << wrn << endl;
}