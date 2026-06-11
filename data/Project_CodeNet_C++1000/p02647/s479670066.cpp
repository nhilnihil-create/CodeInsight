#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, k;
    cin >> n >> k;
    vll a(n);
    REP(i, n) cin >> a[i];
    ll end = 0;
    REP(x, k) {
        vll c(n + 1), b(n);
        REP(i, n) {
            c[max(i - a[i], 0LL)]++;
            c[min(i + a[i] + 1, n)]--;
        }
        b[0] = c[0];
        REP(i, n - 1) {
            b[i + 1] = min(b[i] + c[i + 1], n);
        }
        a = b;
        end = 1;
        REP(i, n) {
            if (a[i] != n) end = 0;
        }
        if (end) break;
    }
    REP(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}