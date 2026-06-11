#include <bits/stdc++.h>
using namespace std;
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
    cout << fixed << setprecision(10);
    ll N; cin >> N;
    vector<ld> x(N), y(N);
    vector<ll> v(N);
    rep(i, N) {
        cin >> x[i] >> y[i];
        v[i] = i + 1;
    }

    ld pcnt = 0, sum = 0;
    do {
        rep(i, N - 1) {
            sum += sqrt(pow((x[v[i] - 1] - x[v[i + 1] - 1]), 2) + pow((y[v[i] - 1] - y[v[i + 1] - 1]), 2));
        }
        pcnt++;
    } while (next_permutation(v.begin(), v.end()));
    ld ans = sum / pcnt;
    cout << ans << endl;
}